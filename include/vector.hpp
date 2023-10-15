#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__
#include <memory>
#include <cstring>
#include <cstddef>
#include <exception>
#include "type_traits.hpp"
#include "iterator.hpp"
#include "algorithm.hpp"
#include "utility.hpp"

namespace ft
{
	template<typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef				T												value_type;
		typedef				Alloc											allocator_type;
		typedef	typename	allocator_type::reference						reference;
		typedef typename	allocator_type::const_reference					const_reference;
		typedef	typename	allocator_type::pointer							pointer;
		typedef typename	allocator_type::const_pointer					const_pointer;
		typedef typename	ft::random_access_iterator<value_type> 			iterator;
		typedef typename	ft::random_access_iterator<const value_type>	const_iterator;
		typedef typename	ft::reverse_iterator<iterator> 					reverse_iterator;
		typedef typename	ft::reverse_iterator<const_iterator> 			const_reverse_iterator;
		typedef size_t														size_type;
		typedef ptrdiff_t													difference_type;

	private:
		pointer	_begin;
		pointer	_end;
		pointer	_capacity_end;
		allocator_type	_alloc;

		template <typename U>
		void	__swap(U& lhs, U& rhs);

		template <typename InputIterator>
		difference_type		__distance(InputIterator first, InputIterator last);

		template <typename Integral>
		void	__insert_using_n_val(iterator position, Integral n, Integral val);

		template <typename InputIterator>
		void	__insert_realloc(iterator position, InputIterator first, InputIterator last, ft::false_type);
		template <typename Integral>
		void	__insert_realloc(iterator position, Integral n, Integral val, ft::true_type);

		template <typename InputIterator>
		void	__insert_to_reserve_space(iterator position, InputIterator first, InputIterator last, ft::false_type);
		template <typename Integral>
		void	__insert_to_reserve_space(iterator position, Integral n, Integral val, ft::true_type);

		template <class InputIterator>
		void	__insert_dispatch(iterator position, InputIterator first, InputIterator last, const typename ft::enable_if<!(ft::is_integral<InputIterator>::value), bool>::type& integral_type);
		template <class Integral>
		void	__insert_dispatch(iterator position, Integral n, Integral val, const typename ft::enable_if<ft::is_integral<Integral>::value, bool>::type& integral_type);

		void	__assign_fill(size_type n, const value_type& val);

		template <class Integral>
		void 	__assign_dispatch(Integral n, Integral val, const typename ft::enable_if<ft::is_integral<Integral>::value, bool>::type& integral_type);
		template <class InputIterator>
		void 	__assign_dispatch(InputIterator first, InputIterator last, const typename ft::enable_if<!(ft::is_integral<InputIterator>::value), bool>::type& integral_type);

	public:
		// # constructor && destructor
		explicit vector(const allocator_type& alloc = allocator_type());
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());
	
		template <typename InputIterator>
		vector(InputIterator first, InputIterator last,
						const allocator_type& alloc = allocator_type());
		vector(const vector& x);
		virtual ~vector();

		// operator
		vector&	operator=(const vector& org_vector);
		
		// Iterator
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		// capacity
		size_type				size() const;
		size_type				max_size() const;
		void 					resize(size_type n, value_type val = value_type());
		size_type 				capacity() const;
		bool 					empty() const;
		void 					reserve(size_type n);

		// element access
		reference 				operator[](size_type n);
		const_reference 		operator[](size_type n) const;
		reference 				at(size_type n);
		const_reference 		at(size_type n) const;
		reference 				front();
		const_reference 		front() const;
		reference 				back();
		const_reference 		back() const;

		// modifiers
		template <class InputIterator>
		void 					assign(InputIterator first, InputIterator last);

		void 					assign(size_type n, const value_type& val);
		void 					push_back(const value_type& val);
		void 					pop_back();

		iterator 				insert(iterator position, const value_type& val);
		void 					insert(iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void 					insert(iterator position, InputIterator first, InputIterator last);

		iterator 				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void 					swap(vector& x);
		void 					clear();

		// allocator
		allocator_type 			get_allocator() const;

	};

	// ---------------------------------------------------------------------------
	// -------------------------------- Define -----------------------------------
	// ---------------------------------------------------------------------------
    template <typename T, typename Alloc>
    template <typename U>
    inline void vector<T, Alloc>::__swap(U &lhs, U &rhs)
    {
		U	tmp;

		tmp = lhs;
		lhs = rhs;
		rhs = tmp;
    }

    template <typename T, typename Alloc>
    template <typename InputIterator>
    inline typename vector<T, Alloc>::difference_type vector<T, Alloc>::__distance(InputIterator first, InputIterator last)
    {
        typename iterator_traits<InputIterator>::difference_type len(0);
		for (; first != last; ++first)
			++len;
		return len;
    }

	template <typename T, typename Alloc>
	template <class InputIterator>
	inline void vector<T, Alloc>::__assign_dispatch(InputIterator first, InputIterator last, const typename ft::enable_if<!(ft::is_integral<InputIterator>::value), bool>::type& integral_type)
	{
		difference_type	n;

		(void)integral_type;
		n = this->__distance(first, last);
		this->reserve(static_cast<size_type>(n));
		std::uninitialized_copy(first, last, this->_begin);
		this->_end = this->_begin + n;
	}

	template <typename T, typename Alloc>
	template <class Integral>
	inline void vector<T, Alloc>::__assign_dispatch(Integral n, Integral val, const typename ft::enable_if<ft::is_integral<Integral>::value, bool>::type& integral_type)
	{
		(void)integral_type;
		this->__assign_fill(n, val);
	}

	template <typename T, typename Alloc>
	template <class InputIterator>
	inline void vector<T, Alloc>::__insert_dispatch(iterator position, InputIterator first, InputIterator last, const typename ft::enable_if<!(ft::is_integral<InputIterator>::value), bool>::type &integral_type)
	{
		int	idx;
		difference_type	n;

		(void)integral_type;
		n = this->__distance(first, last);
		idx = position - this->begin();
		if (idx < 0 || idx > static_cast<int>(this->size()))
			throw std::out_of_range("vector::insert -- position is out of range");
		if (this->size() + n > this->capacity())
			this->__insert_realloc(position, first, last, ft::false_type());
		else
			this->__insert_to_reserve_space(position, first, last, ft::false_type());
	}

	template <typename T, typename Alloc>
	template <class Integral>
	inline void vector<T, Alloc>::__insert_dispatch(iterator position, Integral n, Integral val, const typename ft::enable_if<ft::is_integral<Integral>::value, bool>::type& integral_type)
	{
		(void)integral_type;
		this->__insert_using_n_val(position, n, val);
	}


    template <typename T, typename Alloc>
    template <typename Integral>
    inline void vector<T, Alloc>::__insert_using_n_val(iterator position, Integral n, Integral val)
    {
		int	idx;

		idx = position - this->begin();
		if (idx < 0 || idx > static_cast<int>(this->size()))
			throw std::out_of_range("vector::insert -- position is out of range");
		if (this->size() + n > this->capacity())
			this->__insert_realloc(position, n, val, ft::true_type());
		else
			this->__insert_to_reserve_space(position, n, val, ft::true_type());
	}

	template <typename T, typename Alloc>
	template <typename Integral>
	inline void vector<T, Alloc>::__insert_realloc(iterator position, Integral n, Integral val, ft::true_type)
	{
		pointer		new_space;
		size_type	orgin_new_space_idx;
		size_type	orgin_vec_size;

		new_space = NULL;
		orgin_vec_size = this->size();
		new_space = this->_alloc.allocate(this->size() + n);
		std::uninitialized_copy(this->_begin, position.base(), new_space);
		orgin_new_space_idx = position - this->begin();
		for (Integral idx = 0; idx < n; idx++)
			this->_alloc.construct(new_space + orgin_new_space_idx + idx, val);
		std::uninitialized_copy(position.base(), this->_end, (new_space + (orgin_new_space_idx + n)));
		this->clear();
		this->_alloc.deallocate(this->_begin, this->capacity());
		this->_begin = new_space;
		this->_end = this->_begin + orgin_vec_size + n;
		this->_capacity_end = this->_end;
	}

	template <typename T, typename Alloc>
	template <typename InputIterator>
	inline void vector<T, Alloc>::__insert_realloc(iterator position, InputIterator first, InputIterator last, ft::false_type)
	{
		pointer		new_space;
		size_type	orgin_new_space_idx;
		size_type	orgin_vec_size;
		difference_type	n;

		n = this->__distance(first, last);
		orgin_vec_size = this->size();
		new_space = this->_alloc.allocate(this->size() + n);
		try
		{
			std::uninitialized_copy(this->begin(), position, new_space);
		}
		catch(...)
		{
			this->_alloc.deallocate(new_space, this->size() + n);
			throw ;
		}

		orgin_new_space_idx = position - this->begin();
		try
		{
			std::uninitialized_copy(first, last, new_space + orgin_new_space_idx);
		}
		catch(...)
		{
			for (size_type idx = 0; idx != orgin_new_space_idx; idx++)
				this->_alloc.destroy(new_space + idx);
			this->_alloc.deallocate(new_space, this->size() + n);
			throw ;
		}

		try
		{
			std::uninitialized_copy(position, this->end(), new_space + (orgin_new_space_idx + n));
		}
		catch(...)
		{
			for (size_type idx = 0; idx != orgin_new_space_idx + n; idx++)
				this->_alloc.destroy(new_space + idx);
			this->_alloc.deallocate(new_space, this->size() + n);
			throw ;
		}
		this->clear();
		this->_alloc.deallocate(this->_begin, this->capacity());
		this->_begin = new_space;
		this->_end = this->_begin + orgin_vec_size + n;
		this->_capacity_end = this->_end;
	}

	template <typename T, typename Alloc>
	template <typename InputIterator>
	inline void vector<T, Alloc>::__insert_to_reserve_space(iterator position, InputIterator first, InputIterator last, ft::false_type)
	{
		difference_type	n;

		if (position == this->end())
		{
			for (InputIterator iter = first; iter != last; iter++)
				this->push_back(*iter);
		}
		else
		{
			reverse_iterator reverse_position_begin;
			reverse_iterator reverse_position_end;

			n = this->__distance(first, last);
			reverse_position_begin = static_cast<reverse_iterator>(this->rbegin());
			reverse_position_end = static_cast<reverse_iterator>(position - 1);
			size_type	idx = 0;
			for (reverse_iterator iter = reverse_position_begin; iter != reverse_position_end; iter++, idx++)
				this->_alloc.construct((this->_end - 1) + (n + (idx)), *iter);
			for (iterator iter = position; iter != position + n; iter++, first++)
				this->_alloc.construct(iter.base(), *first);
			this->_end = this->_end + n;
		}
	}
	
	template <typename T, typename Alloc>
	template <typename Integral>
	inline void vector<T, Alloc>::__insert_to_reserve_space(iterator position, Integral n, Integral val, ft::true_type)
	{
		if (position == this->end())
		{
			for (Integral idx = 0; idx < n; idx++)
				this->push_back(val);
		}
		else
		{
			reverse_iterator reverse_position_begin;
			reverse_iterator reverse_position_end;

			reverse_position_begin = static_cast<reverse_iterator>(this->rbegin());
			reverse_position_end = static_cast<reverse_iterator>(position);
			size_type idx = 0;
			for (reverse_iterator iter = reverse_position_begin; iter != reverse_position_end; iter++, idx++)
				this->_alloc.construct((this->_end - 1) + (n + (idx)), *iter);
			for (iterator iter = position; iter != position + n; iter++)
				this->_alloc.construct(iter.base(), val);
			this->_end = this->_end + n;
		}
	}

	template <typename T, typename Alloc>
	inline void	vector<T, Alloc>::__assign_fill(size_type n, const value_type& val)
	{
		this->reserve(n);
		std::uninitialized_fill_n(this->_begin, n, val);
		this->_end = this->_begin + n;
	}

	/*
		----------------------------------
		--public member functions---------
		----------------------------------
	*/
	template<typename T, typename Alloc>
	inline vector<T, Alloc>::vector(const allocator_type& alloc)
		: _begin(NULL), _end(NULL), _capacity_end(NULL), _alloc(alloc)
	{}

	template<typename T, typename Alloc>
	inline vector<T, Alloc>::vector(size_type n, const value_type& val,
					const allocator_type& alloc)
		: _begin(NULL), _end(NULL), _capacity_end(NULL), _alloc(alloc)
	{
		this->assign(n, val);
	}


	template <typename T, typename Alloc>
	template <typename InputIterator>
	inline vector<T, Alloc>::vector(InputIterator first, InputIterator last,
									const allocator_type &alloc)
		: _begin(NULL), _end(NULL), _capacity_end(NULL), _alloc(alloc)
	{
		typedef typename ft::is_integral<InputIterator>::type integral_type;

		this->__assign_dispatch(first, last, integral_type());
	}

	template<typename T, typename Alloc>
	inline vector<T, Alloc>::vector(const vector& x)
		: _begin(NULL), _end(NULL), _capacity_end(NULL), _alloc(x._alloc)
	{
		*this = x;
	}
	
	template<typename T, typename Alloc>
	inline vector<T, Alloc>::~vector()
	{
		this->clear();
		this->_alloc.deallocate(this->_begin, this->capacity());
		this->_capacity_end = this->_begin;
	}

	template<typename T, typename Alloc>
	inline vector<T, Alloc>&	vector<T, Alloc>::operator=(const vector& org_vector)
	{
		if(this != &org_vector)
		{
			this->reserve(org_vector.capacity());
			this->clear();
			std::uninitialized_copy(org_vector.begin(), org_vector.end(), this->begin());
			this->_end = this->_begin + org_vector.size();
			this->_capacity_end = this->_begin + org_vector.capacity();
			this->_alloc = org_vector._alloc;
		}
		return(*this);
	}

	// Iterator
	template<typename T, typename Alloc>
	inline typename vector<T, Alloc>::iterator				vector<T, Alloc>::begin()
	{
		return(iterator(this->_begin));
	}

	template<typename T, typename Alloc>
	inline typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::begin() const
	{
		return(const_iterator(this->_begin));
	}

	template<typename T, typename Alloc>
	inline typename vector<T, Alloc>::iterator				vector<T, Alloc>::end()
	{
		return(iterator(this->_end));
	}

	template<typename T, typename Alloc>
	inline typename vector<T, Alloc>::const_iterator			vector<T, Alloc>::end() const
	{
		return(const_iterator(this->_end));
	}

	template<typename T, typename Alloc>
	inline typename vector<T, Alloc>::reverse_iterator		vector<T, Alloc>::rbegin()
	{
		return(reverse_iterator(this->end()));
	}

	template<typename T, typename Alloc>
	inline typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rbegin() const
	{
		return(const_reverse_iterator(this->end()));
	}

	template<typename T, typename Alloc>
	inline typename vector<T, Alloc>::reverse_iterator		vector<T, Alloc>::rend()
	{
		return(reverse_iterator(this->begin()));
	}

	template<typename T, typename Alloc>
	inline typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rend() const
	{
		return(const_reverse_iterator(this->begin()));
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
	{
		return size_type(this->_end - this->_begin);
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::size_type	vector<T, Alloc>::max_size() const
	{
		return(_alloc.max_size());
	}

	template <typename T, typename Alloc>
	inline void	vector<T, Alloc>::resize(size_type n, value_type val)
	{
		if (n > this->capacity())
			this->reserve(this->capacity() == 0 ? 1 : ft::max(n, 2 * (this->capacity())));
		for (size_type idx = this->size(); idx < n; idx++)
			this->_alloc.construct(&(this->_begin[idx]), val);
		this->_end = this->_begin + n;
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity() const
	{
		return size_type(this->_capacity_end - this->_begin);
	}

	template <typename T, typename Alloc>
	inline bool	vector<T, Alloc>::empty() const
	{
		return bool(this->_begin == this->_end);
	}

	template <typename T, typename Alloc>
	inline void	vector<T, Alloc>::reserve(size_type n)
	{
		size_type	old_size;
		pointer		new_space;

		if(this->capacity() < n)
		{
			new_space = this->_alloc.allocate(n);
			for(size_type idx = 0; idx < this->size(); idx++)
				new_space[idx] = this->_begin[idx];
			old_size = this->size();
			if (this->_begin)
			{
				this->clear();
				this->_alloc.deallocate(this->_begin, this->capacity());
			}
			this->_begin = new_space;
			this->_end = this->_begin + old_size;
			this->_capacity_end = this->_begin + n;
		}
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::reference	vector<T, Alloc>::operator[](size_type n)
	{
		return(*(this->_begin + n));
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::const_reference	vector<T, Alloc>::operator[](size_type n) const
	{
		return(*(this->_begin + n));
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::reference	vector<T, Alloc>::at(size_type n)
	{
		if(n >= this->size())
			throw std::out_of_range("vector::at -- out of range");
		return(*(this->_begin + n));
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::const_reference	vector<T, Alloc>::at(size_type n) const
	{
		if(n >= this->size())
			throw std::out_of_range("vector::at -- out of range");
		const_reference	lvalue = *(this->_begin + n);
		return(lvalue);
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::reference	vector<T, Alloc>::front()
	{
		return(*(this->_begin));
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::const_reference	vector<T, Alloc>::front() const
	{
		return(*(this->_begin));
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::reference	vector<T, Alloc>::back()
	{
		return(*(this->_end - 1));
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::const_reference	vector<T, Alloc>::back() const
	{
		return(*(this->_end - 1));
	}

	template <typename T, typename Alloc>
	template <class InputIterator> 
	inline void vector<T, Alloc>::assign(InputIterator first, InputIterator last)
	{
		typedef typename ft::is_integral<InputIterator>::type integral_type;

		this->__assign_dispatch(first, last, integral_type());
	}

	template <typename T, typename Alloc>
	inline void	vector<T, Alloc>::assign(size_type n, const value_type& val)
	{
		this->__assign_fill(n, val);
	}
	
	/*
		- capa이내일때 아닐때 2가지 경우
	*/
	template<typename T, typename Alloc>
	inline	void	vector<T, Alloc>::push_back(const value_type& val)
	{
		if (this->size() == this->capacity())
			this->reserve(this->capacity() == 0 ? 1 : 2 * (this->capacity()));
		this->_alloc.construct(this->_end, val);
		this->_end++;
	}

	template<typename T, typename Alloc>
	inline	void	vector<T, Alloc>::pop_back()
	{
		if (this->empty())
			throw std::out_of_range("vector::pop_back -- vector is empty");
		this->_end--;
		this->_alloc.destroy(this->_end);
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator position, const value_type& val)
	{
		difference_type	n;

		n = (position - this->begin());
		this->insert(position, 1, val);
		return (this->begin() + n);
	}

	template <typename T, typename Alloc>
	inline void	vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
	{
		this->__insert_using_n_val(position, n, val);
	}

	template <typename T, typename Alloc>
	template <class InputIterator>
	inline void	vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
	{
		typedef typename ft::is_integral<InputIterator>::type integral_type;

		this->__insert_dispatch(position, first, last, integral_type());
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator position)
	{
		return (erase(position, position + 1));
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator first, iterator last)
	{
		if (first > end() || last < begin())
			throw std::out_of_range("vector::erase -- out of range");
		for (iterator iter = first; iter != last; iter++)
			this->_alloc.destroy(iter.base());
		std::memmove(static_cast<void *>(first.base()), static_cast<void *>(last.base()), sizeof(value_type) * (this->end() - last));
		this->_end -= last - first;
		return (first);
	}

	template <typename T, typename Alloc>
	inline void	vector<T, Alloc>::swap(vector& x)
	{
		this->__swap(x._begin, this->_begin);
		this->__swap(x._end, this->_end);
		this->__swap(x._capacity_end, this->_capacity_end);
		this->__swap(x._alloc, this->_alloc);
	}

	template <typename T, typename Alloc>
	inline void	vector<T, Alloc>::clear()
	{
		for (iterator iter = this->begin(); iter != this->end(); iter++)
			this->_alloc.destroy(iter.base());
		this->_end = this->_begin;
	}

	template <typename T, typename Alloc>
	inline typename vector<T, Alloc>::allocator_type	vector<T, Alloc>::get_allocator() const
	{
		return (this->_alloc);
	}

	// non-member function
	template <class T, class Alloc>
	inline bool operator==(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{
		if (x.size() != y.size())
			return (false);
		return(ft::equal(x.begin(), x.end(), y.begin()));
	}

	template <class T, class Alloc>
	inline bool operator!=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{
		return(!(x == y));
	}

	template <class T, class Alloc>
	inline bool operator<(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{
		return(ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}

	template <class T, class Alloc>
	inline bool operator<=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{
		return(!(y < x));
	}
	
	template <class T, class Alloc>
	inline bool operator>(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{
		return(y < x);
	}

	template <class T, class Alloc>
	inline bool operator>=(const vector<T,Alloc>& x, const vector<T,Alloc>& y)
	{
		return(!(x < y));
	}

	template <class T, class Alloc>
  	inline void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
