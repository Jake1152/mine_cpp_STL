#ifndef __MAP_ITERATOR__
#define __MAP_ITERATOR__

#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "utility.hpp"
#include "avl_tree.hpp"

namespace ft
{
	/*
		- bidirectional_iterator 구현에 대한 나만의 생각
		이것의 역할은 무엇인가
		그 역할을 위해 구체적으로 필요한 것들은 무엇인가
		그 역할을 원활하게 되게하기 위해서 어떤식으로 구현해주는 것이 좋을 것인가?
	*/
	template<typename Key, typename Value>
	class bidirectional_iterator
		// : public iterator<typename iterator_traits<pair<Key, Value> *>::iterator_category,
		//                 typename iterator_traits<pair<Key, Value> *>::value_type,
		//                 typename iterator_traits<pair<Key, Value> *>::difference_type,
		//                 typename iterator_traits<pair<Key, Value> *>::pointer,
		//                 typename iterator_traits<pair<Key, Value> *>::reference>
	{
	public:
		typedef pair<Key, Value>*										pair_type;
		typedef node<const Key, const Value>*							const_iterator_type;
		typedef typename iterator_traits<pair_type>::difference_type	difference_type;
		typedef typename iterator_traits<pair_type>::reference			reference;
		typedef typename iterator_traits<pair_type>::pointer             pointer;
		typedef typename iterator_traits<pair_type>::value_type          value_type;
		typedef			 std::bidirectional_iterator_tag                 iterator_category;

	private:
		node<Key, Value> *_current;

	public:
		bidirectional_iterator();
		explicit bidirectional_iterator(node<Key, Value> *current);
		bidirectional_iterator(const bidirectional_iterator& org_iter);
		virtual ~bidirectional_iterator();
		
		bidirectional_iterator& operator=(const bidirectional_iterator& org_bidirectional_iterator);

		node<Key, Value>*   base() const;
		reference operator*() const;
		bidirectional_iterator& operator++();
		bidirectional_iterator  operator++(int);
		bidirectional_iterator& operator--();
		bidirectional_iterator  operator--(int);
		pointer operator->() const;

		operator bidirectional_iterator<const Key, const Value>() const;
		bool operator==(const bidirectional_iterator &other_bidirectional_iter) const;
		bool operator!=(const bidirectional_iterator &other_bidirectional_iter) const;

	};
	/*
		-------------------------------------------------
		--define bidirectional iterator access iterator--
		-------------------------------------------------
	*/
	template<typename Key, typename Value>
	inline bidirectional_iterator<Key, Value>::bidirectional_iterator()
		: _current(NULL)
	{}
	
	template<typename Key, typename Value>
	inline bidirectional_iterator<Key, Value>::bidirectional_iterator(node<Key, Value> *current)
		: _current(current)
	{}

	template<typename Key, typename Value>
	inline bidirectional_iterator<Key, Value>::bidirectional_iterator(const bidirectional_iterator& org)
		: _current(org._current)
	{}

	template<typename Key, typename Value>
	inline bidirectional_iterator<Key, Value>::~bidirectional_iterator()
	{}

	template<typename Key, typename Value>
	inline bidirectional_iterator<Key, Value>& bidirectional_iterator<Key, Value>::operator=(const bidirectional_iterator& org_bidirectional_iterator)
	{
		if (this != &org_bidirectional_iterator)
			this->_current = org_bidirectional_iterator._current;
		return (*this);
	}

	template<typename Key, typename Value>
	inline node<Key, Value>* bidirectional_iterator<Key, Value>::base() const
	{
		return (this->_current);
	}

	template<typename Key, typename Value>
	inline typename bidirectional_iterator<Key, Value>::reference bidirectional_iterator<Key, Value>::operator*() const
	{   
		return (this->_current->_value);
	}

	template<typename Key, typename Value>
	inline bidirectional_iterator<Key, Value>& bidirectional_iterator<Key, Value>::operator++()
	{
		this->_current = this->_current->next();
		return (*this);
	}

	template<typename Key, typename Value>
	inline bidirectional_iterator<Key, Value> bidirectional_iterator<Key, Value>::operator++(int)
	{
		// next()
		bidirectional_iterator  prev_bidirectional_iterator = *this;
		this->_current = this->_current->next();
		return prev_bidirectional_iterator;
	}

	template<typename Key, typename Value>
	inline bidirectional_iterator<Key, Value> &bidirectional_iterator<Key, Value>::operator--()
	{
		this->_current = this->_current->prev();
		return (*this);
	}

	template<typename Key, typename Value>
	inline bidirectional_iterator<Key, Value> bidirectional_iterator<Key, Value>::operator--(int)
	{
		bidirectional_iterator  prev_bidirectional_iterator(*this);
		// this->_current--;
		this->_current = this->_current->prev();
		return prev_bidirectional_iterator;
	}

	template<typename Key, typename Value>
	inline typename bidirectional_iterator<Key, Value>::pointer bidirectional_iterator<Key, Value>::operator->() const
	{
		return (&(operator*()));
	}

    template <typename Key, typename Value>
    inline bool bidirectional_iterator<Key, Value>::operator==(const bidirectional_iterator &other_bidirectional_iter) const
    {
		return (this->_current == other_bidirectional_iter._current);
    }

	template <typename Key, typename Value>
    inline bool bidirectional_iterator<Key, Value>::operator!=(const bidirectional_iterator &other_bidirectional_iter) const
    {
		return (this->_current != other_bidirectional_iter._current);
    }

    template <typename Key, typename Value>
    inline bidirectional_iterator<Key, Value>::operator bidirectional_iterator<const Key, const Value>() const
    {
		return (bidirectional_iterator<const Key, const Value>((node<const Key, const Value> *)(this->_current)));
	}

    template<typename Key, typename Value>
	bool operator==(const bidirectional_iterator<Key, Value> &lhs, const bidirectional_iterator<Key, Value> &rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename Key, typename Value>
	bool operator!=(const bidirectional_iterator<Key, Value> &lhs, const bidirectional_iterator<Key, Value> &rhs)
	{
		return (lhs.base() != rhs.base());
	}
}

#endif