#ifndef __MAP_HPP__
#define __MAP_HPP__

// #include <functional>
#include <memory>
#include "map_iterator.hpp"
#include "avl_tree.hpp"
#include "utility.hpp"

namespace ft
{
	template <typename Key, // map::key_type
			  typename Value, // map::mapped_type
			  typename Compare = std::less<Key>, // map::key_compare
			  typename Alloc = std::allocator<ft::pair<const Key, Value> >  // map::allocator_type           
			  >
	class map
	{
	public:
		// member type	definition	notes
		typedef Key																					key_type;
		typedef Value																				mapped_type;
		typedef ft::pair<const Key, Value>															value_type;
		typedef Compare																				key_compare;
		typedef Alloc																				allocator_type;
		typedef typename allocator_type::reference													reference;
		typedef typename allocator_type::const_reference											const_reference;
		typedef typename allocator_type::pointer													pointer;
		typedef typename allocator_type::const_pointer												const_pointer;
		typedef typename allocator_type::size_type													size_type;
		typedef typename allocator_type::difference_type											difference_type;
		typedef ft::bidirectional_iterator<key_type, mapped_type>									iterator;
		typedef ft::bidirectional_iterator<const key_type, const mapped_type>						const_iterator;
		typedef ft::reverse_iterator<iterator>														reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>												const_reverse_iterator;
		typedef typename ft::avl_tree<key_type, mapped_type, key_compare, allocator_type> 			tree_type;
		typedef typename tree_type::node_ptr														node_ptr;

		class value_compare
		{
			friend class map;
		protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}
		public:
			typedef bool		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

	private:
		tree_type		_tree;
		key_compare		_comp;
		allocator_type	_alloc;

		template <class T>
        void __swap(T &a, T &b);

	public:
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last);

		// empty (1)
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(comp, alloc), _comp(comp), _alloc(alloc)
		{}
		// range (2)	
		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(comp, alloc), _comp(comp), _alloc(alloc)
		{
			insert(first, last);
		}
		// copy (3)	
		map (const map& x)
			: _tree(x._comp, x._alloc), _comp(x._comp), _alloc(x._alloc)
		{
			*this = x;
		}

		map	&operator=(const map& origin_map)
		{
			if (this != &origin_map)
			{
				this->clear();
				insert(origin_map.begin(), origin_map.end());
			}
			return (*this);
		}

		virtual ~map()
		{}

		key_compare key_comp()
		{
			return (_tree.key_comp());
		}

		const key_compare& key_comp() const
		{
			return (_tree.key_comp());
		}

		value_compare value_comp() const
		{
			return value_compare(_tree.key_comp());
		}

		allocator_type get_allocator() const
		{
			return this->_alloc;
		}

		iterator begin() 
		{
			return iterator(_tree.begin());
		}

		const_iterator begin() const 
		{
			return iterator(_tree.begin());
		}

		iterator end() 
		{
			return iterator(_tree.end());
		}

		const_iterator end() const 
		{
			return iterator(_tree.end());
		}

		reverse_iterator rbegin() 
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
		  return const_reverse_iterator(end());
		}

		reverse_iterator rend() 
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const 
		{
			return const_reverse_iterator(begin());
		}

		bool empty() const 
		{
			return (this->_tree.empty());
		}

		size_type size() const 
		{
			return (this->_tree.size());
		}

		size_type max_size() const
		{
			return _alloc.max_size();
		}

		mapped_type& operator[](const key_type& x)
		{
			iterator iter;

			iter = find(x);
			if (iter == end())
				iter = insert(ft::make_pair(x, mapped_type())).first;
			return (iter->second);
		}

		void swap(map& x) 
		{
			this->_tree.swap(x._tree);
			this->__swap(this->_comp, x._comp);
			this->__swap(this->_alloc, x._alloc);
		}

		pair<iterator,bool>	insert(const value_type& x)
		{
			iterator iter = find(x.first);
			if (iter == end())
			{
				this->_tree.insert(x);
				return ft::make_pair(iterator(_tree.find(x.first)), true);
			}
			return ft::make_pair(iter, false);
		}
		
		iterator insert(iterator position, const value_type& x)
		{
			(void)position;
			return iterator(insert(x).first);
		}
		
		void erase(iterator position)
		{
			this->_tree.erase(position->first);
		}

		size_type erase(const key_type& x)
		{
			return this->_tree.erase(x);
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator iter = first;
				value_type val = *++first;
				erase(iter);
				if (first != last)
					first = find(val.first);
			}
		}

		void clear()
		{
			this->_tree.clear();
		}

		iterator find(const key_type& x)
		{
			node_ptr	find_node;
			
			find_node = this->_tree.find(x);
			if (find_node == NULL)
				return end();
			return iterator(find_node);
		}

		const_iterator find(const key_type& x) const
		 {
			node_ptr	find_node;

			find_node = this->_tree.find(x);
			if (find_node == NULL)
				return (end());
			return iterator(find_node);
		}

		size_type count(const key_type& x) const
		{
			return (find(x) == end() ? 0 : 1);
		}

		// >= (greater then and equal)
		iterator lower_bound(const key_type& x)
		{
			iterator it;

			it = begin();
			while (it != end() && key_comp()(it->first, x))
				++it;
			return it;
		}
		
		const_iterator lower_bound(const key_type& x) const
		{
			const_iterator it;

			it = begin();
			while (it != end() && key_comp()(it->first, x))
				++it;
			return it;
		}

		// < (less then)
		iterator upper_bound(const key_type& x)
		{
			iterator it;

			it = begin();
			while (it != end() && !key_comp()(x, it->first))
				++it;
			return it;
		}

		const_iterator upper_bound(const key_type& x) const
		{
			const_iterator it;

			it = begin();
			while (it != end() && !key_comp()(x, it->first))
				++it;
			return it;
		}

		pair<iterator,iterator> equal_range(const key_type& x)
		{
			
			return (ft::make_pair(lower_bound(x), upper_bound(x)));
		}

		pair<const_iterator,const_iterator> equal_range(const key_type& x) const
		{
			return (ft::make_pair(lower_bound(x), upper_bound(x)));
		}
    };

    template <class key_type, class  mapped_type, class key_compare, class allocator_type>
	inline bool operator==(const map<key_type, mapped_type, key_compare, allocator_type>& x, 
						const map<key_type, mapped_type, key_compare, allocator_type>& y)
	{
		return ((x.size() == y.size()) && ft::equal(x.begin(), x.end(), y.begin()));
	}

	template <class key_type, class  mapped_type, class key_compare, class allocator_type>
	inline bool operator<(const map<key_type, mapped_type, key_compare, allocator_type>& x, 
						const map<key_type, mapped_type, key_compare, allocator_type>& y)
	{
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}

	template <class key_type, class  mapped_type, class key_compare, class allocator_type>
	inline bool operator!=(const map<key_type, mapped_type, key_compare, allocator_type>& x, 
						const map<key_type, mapped_type, key_compare, allocator_type>& y)
	{
		return (!(x == y));
	}

	template <class key_type, class  mapped_type, class key_compare, class allocator_type>
	inline bool operator>(const map<key_type, mapped_type, key_compare, allocator_type>& x, 
						const map<key_type, mapped_type, key_compare, allocator_type>& y)
	{
		return (y < x);
	}

	template <class key_type, class  mapped_type, class key_compare, class allocator_type>
	inline bool operator<=(const map<key_type, mapped_type, key_compare, allocator_type>& x, 
						const map<key_type, mapped_type, key_compare, allocator_type>& y)
	{
		return (!(y < x));
	}

	template <class key_type, class  mapped_type, class key_compare, class allocator_type>
	inline bool operator>=(const map<key_type, mapped_type, key_compare, allocator_type>& x, 
						const map<key_type, mapped_type, key_compare, allocator_type>& y)
	{
		return (!(x < y));
	}
	
    template <typename Key, typename Value, typename Compare, typename Alloc>
    template <class T>
    inline void map<Key, Value, Compare, Alloc>::__swap(T &a, T &b)
	{
		T tmp;

		tmp = a;
		a = b;
		b = tmp;
	}

    template <typename Key, typename Value, typename Compare, typename Alloc>
    template <class InputIterator>
    inline void map<Key, Value, Compare, Alloc>::insert(InputIterator first, InputIterator last)
    {
		for (InputIterator iter = first; iter != last; iter++)
			insert(*iter);
	}
		
    template <class key_type, class  mapped_type, class key_compare, class allocator_type>
	inline void swap(map<key_type, mapped_type, key_compare, allocator_type>& x, 
					map<key_type, mapped_type, key_compare, allocator_type>& y)
	{
		x.swap(y);
	}
}

#endif