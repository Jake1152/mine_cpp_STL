#ifndef __AVL_TREE_HPP__
#define __AVL_TREE_HPP__

#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <memory>

#include "algorithm.hpp"
#include "utility.hpp"

namespace ft
{
	template <typename Key, typename Value>
	struct node
	{
	public:
		typedef typename ft::pair<Key, Value>	value_type;
		typedef node<Key, Value>*				node_ptr;

		node_ptr	_parent;
		node_ptr	_left;
		node_ptr	_right;
		value_type	_value;

		node(void);
		explicit node(const value_type& value);
		explicit node(const Key& key, const Value& value);
		~node(void);
		void print_node(void);

		node_ptr	next();
		node_ptr	prev();
		// node_ptr	parent();
	};

	// _value(value_type()) -> default initialization!
	template  <typename Key, typename Value>
	inline node<Key, Value>::node(void)
		: _parent(NULL), _left(NULL), _right(NULL), _value(value_type())
	{}

	template <typename Key, typename Value>
	inline node<Key, Value>::node(const value_type &value)
		: _parent(NULL), _left(NULL), _right(NULL), _value(value)
	{}

	template  <typename Key, typename Value>
	inline node<Key, Value>::node(const Key& key, const Value& value)
		: _parent(NULL), _left(NULL), _right(NULL)
	{
		this->_value = ft::make_pair(key, value);
	}

	template <typename Key, typename Value>
	inline node<Key, Value>::~node(void)
	{}

	template <typename Key, typename Value>
	inline void node<Key, Value>::print_node(void)
	{
		

		std::cout << "#=============== node info ====================#" << std::endl;
		std::cout << "current node value is first : " << this->_value.first << " #second : " << this->_value.second << std::endl;
		if (this->_parent)
			std::cout << "parent node value is first : " << this->_parent->_value.first << " #second : " << this->_parent->_value.second << std::endl;
		if (this->_left)
			std::cout << "left node value is first : " << this->_left->_value.first << " #second : " << this->_left->_value.second << std::endl;
		if (this->_right)
			std::cout << "right node value is first : " << this->_right->_value.first << " #second : " << this->_right->_value.second << std::endl;
		std::cout << "#=============================================#" << std::endl;
		std::cout << std::endl;
	}

	/*
		내가 root일때?
		후계자 찾기와 비슷
	*/
	template <typename Key, typename Value>
	inline typename node<Key, Value>::node_ptr node<Key, Value>::next()
	{
		node_ptr	cur_node;

		if (this->_right)
		{
			cur_node = this->_right;
			while (cur_node->_left)
				cur_node = cur_node->_left;
		}
		else
		{
			cur_node = this;
			while (cur_node->_parent && cur_node->_parent->_right == cur_node)
				cur_node = cur_node->_parent;
			cur_node = cur_node->_parent;
			if (cur_node == NULL)
				throw std::out_of_range("check next node out of range");
		}
		return (cur_node);
	}

	template <typename Key, typename Value>
	inline typename node<Key, Value>::node_ptr node<Key, Value>::prev()
	{
		node_ptr	cur_node;

		if (this->_left)
		{
			cur_node = this->_left;
			while (cur_node->_right)
				cur_node = cur_node->_right;
		}
		else
		{
			cur_node = this;
			while (cur_node->_parent && cur_node->_parent->_left == cur_node)
				cur_node = cur_node->_parent;
			cur_node = cur_node->_parent;
			if (cur_node == NULL)
				throw std::out_of_range("check prev node out of range");
		}
		return (cur_node);
	}

	/*
		------------------
		--- avl tree -----
		------------------
	*/
	template <typename Key, typename Value, typename Compare = std::less<Key>, typename Alloc = std::allocator<ft::pair<Key, Value> > >
	class   avl_tree
	{
	// member type
	public:
		typedef Key																	key_type;
		typedef Value																mapped_type;
		typedef typename ft::pair<key_type, mapped_type>							value_type;
		typedef typename ft::node<key_type, mapped_type>							node;
		typedef typename ft::node<key_type, mapped_type>*							node_ptr;
		typedef Compare																key_compare;
		typedef Alloc																allocator_type;
		typedef typename allocator_type::template rebind<node >::other				rebind_type;

	private:
		node_ptr   	_root;
		size_t		_size;
		key_compare	_comp;
		rebind_type	_alloc;
		node_ptr	_end;

		node    	__insert_normal(const key_type& key, const mapped_type& value);
		size_t		__erase(const key_type& key);
		node_ptr	__get_leftmost() const;
		void		__remove_all(node_ptr be_removed_node);
		
		template<typename T>
		void		__swap(T &a, T& b);

	public:
		// avl_tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		// template <typename Key, typename Value, typename Compare, typename Alloc>
		avl_tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _root(NULL), _size(0), _comp(comp), _alloc(alloc)
		{
			this->_end = this->_alloc.allocate(1);
			this->_alloc.construct(this->_end, node());
		}

		virtual ~avl_tree();

		node    	insert(value_type value);
		size_t    	erase(const key_type& key);
		node_ptr	find(const key_type& key) const;
		node_ptr	find_successor(const node_ptr& cur_node);
		node_ptr	find_left_side_successor(const node_ptr& cur_node);
		node_ptr	find_right_side_successor(const node_ptr& cur_node);

		void		print_tree(void);
		void		preorder(const node_ptr& cur_node);
		void		postorder(const node_ptr& cur_node);
		void		inorder(const node_ptr& cur_node);

		node_ptr	get_root(void) const;
		size_t		get_height(const node_ptr& cur_node);
		int			get_balance_factor(const node_ptr& cur_node);

		void		balance_routine(node_ptr cur_node);
		void		rebalance(const node_ptr& cur_node, const int& balance_factor);

		void		RR_rotation(node_ptr parent);
		void		LL_rotation(node_ptr parent);
		void		LR_rotation(node_ptr parent);
		void		RL_rotation(node_ptr parent);

		void		clear();
		size_t		size() const;

		node_ptr	begin() const;
		node_ptr	end() const;
		bool		empty() const;
		void		swap(avl_tree& other_avl_tree);
		
		key_compare& key_comp();
		const key_compare& key_comp() const;
	};

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline avl_tree<Key, Value, Compare, Alloc>::~avl_tree()
	{
		clear();
		this->_alloc.destroy(this->_end);
		this->_alloc.deallocate(this->_end, 1);
	}
	
	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline typename avl_tree<Key, Value, Compare, Alloc>::node avl_tree<Key, Value, Compare, Alloc>::__insert_normal(const key_type& key, const mapped_type& value)
	{
		node_ptr	cur_node;

		if (this->get_root() == NULL)
		{
			this->_root = this->_alloc.allocate(1);
			this->_alloc.construct(this->_root, node(key, value));
			return (node(key, value));
		}
		cur_node = this->get_root();
		while (cur_node)
		{
			if (key_comp()(cur_node->_value.first, key))
			{
				if (cur_node->_right == NULL)
				{
					cur_node->_right = this->_alloc.allocate(1);
					this->_alloc.construct(cur_node->_right, node(key, value));
					cur_node->_right->_parent = cur_node; // parent
					break ;
				}
				cur_node = cur_node->_right;
			}
			else if (key_comp()(key, cur_node->_value.first))
			{
				if (cur_node->_left == NULL)
				{
					cur_node->_left = this->_alloc.allocate(1);
					this->_alloc.construct(cur_node->_left, node(key, value));
					cur_node->_left->_parent = cur_node; 
					break ;
				}
				cur_node = cur_node->_left;
			}
			else
				return (node());
		}
		return (node(key, value));
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline typename avl_tree<Key, Value, Compare, Alloc>::node avl_tree<Key, Value, Compare, Alloc>::insert(value_type value)
	{
		node_ptr	cur_node;
		node		ret_node;

		if (this->_end->_parent)
		{
			this->_end->_parent->_right = NULL;
			this->_end->_parent = NULL;
		}
		ret_node = this->__insert_normal(value.first, value.second);
		balance_routine(find(value.first));
		_size += 1;
		cur_node = this->_root;
		while (cur_node->_right)
			cur_node = cur_node->_right;
		this->_end->_parent = cur_node;
		cur_node->_right = this->_end;
		return (ret_node);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline size_t	avl_tree<Key, Value, Compare, Alloc>::erase(const key_type &key)
	{
		size_t		ret_erase;
		node_ptr	cur_node;
		
		if (this->_end->_parent)
		{
			this->_end->_parent->_right = NULL;
			this->_end->_parent = NULL;
		}
		ret_erase = this->__erase(key);
		cur_node = this->_root;
		while (cur_node && cur_node->_right)
			cur_node = cur_node->_right;
		this->_end->_parent = cur_node;
		if (cur_node)
			cur_node->_right = this->_end;
		return (ret_erase);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline typename avl_tree<Key, Value, Compare, Alloc>::node_ptr avl_tree<Key, Value, Compare, Alloc>::find(const key_type &key) const
	{
		node_ptr	cur_node;

		cur_node = this->get_root();
		while (cur_node)
		{
			if (cur_node->_value.first == key)
				return (cur_node);
			else if (_comp(cur_node->_value.first, key))
				cur_node = cur_node->_right;
			else if (_comp(key, cur_node->_value.first))
				cur_node = cur_node->_left;
		}
		return NULL;
	}

	/*
		- 왼쪽에서 가장 큰 값
		- 오른쪽에서 가장 작은 값
	*/
	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline typename avl_tree<Key, Value, Compare, Alloc>::node_ptr avl_tree<Key, Value, Compare, Alloc>::find_successor(const node_ptr& cur_node)
	{
		node_ptr    successor;

		if (cur_node == NULL)
			return (NULL);
		successor = find_left_side_successor(cur_node->_left);
		if (successor == NULL)
			successor = find_right_side_successor(cur_node->_right);
		return (successor);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline typename avl_tree<Key, Value, Compare, Alloc>::node_ptr avl_tree<Key, Value, Compare, Alloc>::find_left_side_successor(const node_ptr& cur_node)
	{
		node_ptr    successor;

		if (cur_node == NULL)
			return (NULL);
		successor = cur_node;
		while (successor->_right)
			successor = successor->_right;
		return (successor);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline typename avl_tree<Key, Value, Compare, Alloc>::node_ptr avl_tree<Key, Value, Compare, Alloc>::find_right_side_successor(const node_ptr& cur_node)
	{
		node_ptr    successor;

		successor = cur_node;
		if (successor == NULL)
			return (NULL);
		while (successor->_left)
			successor = successor->_left;
		return (successor);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline typename avl_tree<Key, Value, Compare, Alloc>::node_ptr avl_tree<Key, Value, Compare, Alloc>::get_root(void) const
	{
		return node_ptr(this->_root);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::print_tree(void)
	{
		node_ptr	cur_node;

		std::cout << "======== print_tree ==========" << std::endl;
		cur_node = this->get_root();
		if (cur_node)
			std::cout << "root is " << cur_node->_value.first << std::endl;
		else
			std::cout << "root is NULL" << std::endl;
		std::cout << "=== preorder ===" << std::endl;
		this->preorder(this->get_root());
		std::cout << std::endl;
		std::cout << "=== inorder ===" << std::endl;
		this->inorder(this->get_root());
		std::cout << std::endl;
		std::cout << "=== postorder ===" << std::endl;
		this->postorder(this->get_root());
		std::cout << std::endl;
	}
	
	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::preorder(const node_ptr& cur_node)
	{
		if (cur_node == NULL)
			return ;
		cur_node->print_node();
		preorder(cur_node->_left);
		preorder(cur_node->_right);
	}
	
	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::postorder(const node_ptr& cur_node)
	{
		if (cur_node == NULL)
			return ;
		postorder(cur_node->_left);
		postorder(cur_node->_right);
		std::cout << cur_node->_value.first << " ";
	}
	
	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::inorder(const node_ptr& cur_node)
	{
		if (cur_node == NULL)
			return ;
		inorder(cur_node->_left);
		std::cout << cur_node->_value.first << " ";
		inorder(cur_node->_right);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline size_t avl_tree<Key, Value, Compare, Alloc>::get_height(const node_ptr& cur_node)
	{
		size_t	height;
		
		height = 0;
		if (cur_node)
			height = 1 + std::max(get_height(cur_node->_left), get_height(cur_node->_right));
		return height;
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline int avl_tree<Key, Value, Compare, Alloc>::get_balance_factor(const node_ptr &cur_node)
	{
		if (cur_node == NULL)
			return 0;
		return (get_height(cur_node->_left) - get_height(cur_node->_right));
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void	avl_tree<Key, Value, Compare, Alloc>::balance_routine(node_ptr cur_node)
	{
		int	balance_factor;

		while (cur_node)
		{
			balance_factor = get_balance_factor(cur_node);
			if (balance_factor > 1 || balance_factor < -1)
				rebalance(cur_node, balance_factor);
			cur_node = cur_node->_parent;
		}
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::rebalance(const node_ptr &cur_node, const int &balance_factor)
	{
		int child_balance_factor;

		if (balance_factor > 1)
		{
			child_balance_factor = get_balance_factor(cur_node->_left);
			if (child_balance_factor > 0) // Left
				LL_rotation(cur_node);
			else // Right
				LR_rotation(cur_node);
		}
		else if (balance_factor < -1)// Right
		{                                           
			child_balance_factor = get_balance_factor(cur_node->_right);
			if (child_balance_factor < 0)  // Right
				RR_rotation(cur_node);
			else // Left
				RL_rotation(cur_node);
		}
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::LL_rotation(node_ptr parent)
	{
		node_ptr	grand_parent;
		node_ptr	child;
		node_ptr	child_right;

		grand_parent = parent->_parent;
		child = parent->_left;
		child_right = child->_right;

		if (parent == this->_root)
			this->_root = child;
		if (grand_parent && grand_parent->_value.first > parent->_value.first)
			grand_parent->_left = child;
		else if (grand_parent)
			grand_parent->_right = child;
		parent->_left = child_right;
		parent->_parent = child;
		child->_right = parent;
		child->_parent = grand_parent;
		if (child_right)
			child_right->_parent = parent;
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::RR_rotation(node_ptr parent)
	{
		node_ptr	grand_parent;
		node_ptr	child;
		node_ptr	child_left;

		grand_parent = parent->_parent;
		child = parent->_right;
		child_left = child->_left;

		if (parent == this->_root)
			this->_root = child;
		if (grand_parent && grand_parent->_value.first > parent->_value.first)
			grand_parent->_left = child;
		else if (grand_parent)
			grand_parent->_right = child;
		parent->_right = child_left;
		parent->_parent = child;
		child->_left = parent;
		child->_parent = grand_parent;
		if (child_left)
			child_left->_parent = parent;
	}
	
	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::LR_rotation(node_ptr parent)
	{
		RR_rotation(parent->_left);
		LL_rotation(parent);
	}
	
	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::RL_rotation(node_ptr parent)
	{
		LL_rotation(parent->_right);
		RR_rotation(parent);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::__remove_all(node_ptr be_removed_node)
	{
		(void)be_removed_node;
		while (!empty())
			erase(begin()->_value.first);

		// if (be_removed_node == NULL)
		// 	return ;
		// __remove_all(be_removed_node->_left);
		// __remove_all(be_removed_node->_right);
		// if (this->_end != be_removed_node)
		// if (!end())
		// {
		// 	be_removed_node->_right = NULL;
		// 	be_removed_node->_left = NULL;
		// 	be_removed_node->_parent = NULL;
		// 	this->_alloc.destroy(be_removed_node);
		// 	this->_alloc.deallocate(be_removed_node, 1);
		// }
		// be_removed_node = NULL;
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::clear()
	{
		__remove_all(get_root());
		this->_root = NULL;
		this->_size = 0;
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline size_t avl_tree<Key, Value, Compare, Alloc>::size() const
	{
		return size_t(this->_size);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
    inline typename avl_tree<Key, Value, Compare, Alloc>::key_compare &avl_tree<Key, Value, Compare, Alloc>::key_comp()
    {
		return (this->_comp);
    }

    template <typename Key, typename Value, typename Compare, typename Alloc>
    inline const typename avl_tree<Key, Value, Compare, Alloc>::key_compare &avl_tree<Key, Value, Compare, Alloc>::key_comp() const
    {
		return (this->_comp);
    }

    template <typename Key, typename Value, typename Compare, typename Alloc>
	inline typename avl_tree<Key, Value, Compare, Alloc>::node_ptr avl_tree<Key, Value, Compare, Alloc>::begin() const
	{
		node_ptr	begin_node;

		begin_node = __get_leftmost();
		if (begin_node == NULL)
			return (this->_end);
		return (begin_node);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline typename avl_tree<Key, Value, Compare, Alloc>::node_ptr avl_tree<Key, Value, Compare, Alloc>::end() const
	{
		return (this->_end);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline bool avl_tree<Key, Value, Compare, Alloc>::empty() const
	{
		return (this->_size == 0);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline void avl_tree<Key, Value, Compare, Alloc>::swap(avl_tree &other_avl_tree)
	{
		this->__swap(this->_root, other_avl_tree._root);
		this->__swap(this->_size, other_avl_tree._size);
		this->__swap(this->_comp, other_avl_tree._comp);
		this->__swap(this->_alloc, other_avl_tree._alloc);
		this->__swap(this->_end, other_avl_tree._end);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline size_t avl_tree<Key, Value, Compare, Alloc>::__erase(const key_type &key)
{
		node_ptr	successor;
		node_ptr	be_removed_node;
		node_ptr	be_removed_node_parent;
		node_ptr	successor_parent;

		be_removed_node = find(key);
		if (be_removed_node == NULL)
			return 0; 
		successor = find_successor(be_removed_node);
		be_removed_node_parent = be_removed_node->_parent;
		if (successor == NULL)
		{
			if (be_removed_node_parent && be_removed_node_parent->_left == be_removed_node)
				be_removed_node_parent->_left = NULL;
			else if (be_removed_node_parent && be_removed_node_parent->_right == be_removed_node)
				be_removed_node_parent->_right = NULL;
		}
		else if (successor && (be_removed_node->_left == NULL || be_removed_node->_right == NULL))
		{
			successor_parent = successor->_parent;

			if (successor_parent && successor_parent != be_removed_node && successor_parent->_left == successor)
				successor_parent->_left = successor->_right;
			else if (successor_parent  && successor_parent != be_removed_node && successor_parent->_right == successor)
				successor_parent->_right = successor->_right;

			if (be_removed_node_parent && be_removed_node_parent->_left == be_removed_node)
				be_removed_node_parent->_left = successor;
			else if (be_removed_node_parent && be_removed_node_parent->_right == be_removed_node)
				be_removed_node_parent->_right = successor;

			if (be_removed_node->_left == successor)
				successor->_right = be_removed_node->_right;
			else if (be_removed_node->_right == successor)
				successor->_left = be_removed_node->_left;
			else
			{
				successor->_right = be_removed_node->_right;
				successor->_left = be_removed_node->_left;
			}
			successor->_parent = be_removed_node_parent;
		}
		else
		{
			successor_parent = successor->_parent;

			if (successor_parent != be_removed_node && successor_parent->_left == successor)
			{
				successor_parent->_left = successor->_right;
				if (successor->_right)
					successor->_right->_parent = successor_parent;
			}
			else if (successor_parent != be_removed_node && successor_parent->_right == successor)
			{
				successor_parent->_right = successor->_left;
				if (successor->_left)
					successor->_left->_parent = successor_parent;
			}

			if (be_removed_node_parent && be_removed_node_parent->_left == be_removed_node)
				be_removed_node_parent->_left = successor;
			else if (be_removed_node_parent && be_removed_node_parent->_right == be_removed_node)
				be_removed_node_parent->_right = successor;
				
			if (be_removed_node->_left == successor)
				successor->_right = be_removed_node->_right;
			else if (be_removed_node->_right == successor)
				successor->_left = be_removed_node->_left;
			else
			{
				successor->_left = be_removed_node->_left;
				successor->_right = be_removed_node->_right;
			}
			successor->_parent = be_removed_node_parent;
		}
		if (successor)
		{
			if (be_removed_node->_left && successor !=  be_removed_node->_left && be_removed_node->_left->_parent != successor)
				be_removed_node->_left->_parent = successor;
			if (be_removed_node->_right && successor !=  be_removed_node->_right && be_removed_node->_right->_parent != successor)
				be_removed_node->_right->_parent = successor;
			
		}
		if (be_removed_node == this->_root)
		{
			this->_root = successor;
			if (successor)
				successor->_parent = NULL;
		}
		this->_alloc.destroy(be_removed_node);
		this->_alloc.deallocate(be_removed_node, 1);
		be_removed_node = NULL;
		this->_size -= 1;
		if (successor)
			balance_routine(successor);
		else
			balance_routine(be_removed_node_parent);
		return (1);
	}


	template <typename Key, typename Value, typename Compare, typename Alloc>
	inline typename avl_tree<Key, Value, Compare, Alloc>::node_ptr avl_tree<Key, Value, Compare, Alloc>::__get_leftmost() const
	{
		node_ptr	cur_node;

		cur_node = this->_root;
		while (cur_node && cur_node->_left)
			cur_node = cur_node->_left;
		return (cur_node);
	}

	template <typename Key, typename Value, typename Compare, typename Alloc>
	template <class T>
	inline void avl_tree<Key, Value, Compare, Alloc>::__swap(T &a, T &b)
	{
		T tmp;

		tmp = a;
		a = b;
		b = tmp;
	}
}

#endif