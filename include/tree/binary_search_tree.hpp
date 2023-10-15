#ifndef __BINARY_SEARCH_TREE_HPP__
#define __BINARY_SEARCH_TREE_HPP__

/*
# Tree
node
hirerachi

## BST


### AVL


### RBT

*/

namespace ft
{
    template <typename T>
    struct Node
    {
    public:
        typedef Node<T>* Node_ptr;

        T           _data;
        Node_ptr   _left_child_node;
        Node_ptr   _right_child_node;
        // node_ptr   _parent_node;

        Node();
        explicit Node(const T& data);
        Node(const Node& org_node);
        ~Node();
        
        // Node&   operator=(const Node& org_node);
    };

    template <typename T>
    inline Node<T>::Node()
        : _data(), _left_child_node(NULL), _right_child_node(NULL)
    {}

    template <typename T>
    inline Node<T>::Node(const T& data)
        : _data(data), _left_child_node(NULL), _right_child_node(NULL)
    {}

    template <typename T>
    inline Node<T>::Node(const Node &org_node)
        : _data(org_node._data), _left_child_node(org_node._left_child_node), _right_child_node(org_node._right_child_node)
    {}

    /*
        - node자체를 동적할당한 경우에만 처리한다.
        이부분은 node이다. node 소멸자에서 처리할 것은 없다 판단
        tree에서 node를 가져다 쓰므로 거기서 처리하며
        node의 멤버변수들은 node pointer이거나 node의 value이다
        node pointer는 다른 노드를 가리키고 있다
        그 자식 노드들을 알아서 처리하게 하거나 
        그 자식 노드들을 삭제해야할 이유가 없을 수 있다.
        자식노드들이 삭제된다면 아예 제거하므로 BST의 목적에 맞지 않을 수 있다.
        clear는 다른 문제이므로 특정 노드 삭제에만 관여한다
        그렇게되면 node pointer는 건드리지 않으므로 node의 value만 남는다.
        node value는 T 타입이었으므로 따로 메모리 해제할 것이 없다.
        즉, 소멸자에서 처리할 것은 없다!
    */
    template <typename T>
    inline Node<T>::~Node()
    {}
 
    /*
        해당 노드의 값만 바꿀 것인가
        밑에 노드들도 바꿀 것인가?
        값만 바꾼다면 중복인지 여부를 확인한뒤에 할것인가?
        바꾸는것 자체를 허용할 것인가?
        밑에 노드들도 바꾼다면 기존 노드의 자손 노드들은 다 지울 것인가?

        bst에서 operator=를 허용하지 않기로 한다.
    */
    /*
    template <typename T>
    inline Node &Node<T>::operator=(const Node& org_node)
    {
        if (this != &org_node)
        {
            this->_data = org_node._data;
            this->_left_child_node = org_node._left_child_node;
            this->_right_child_node = org_node._right_child_node;
        }
        return (*this);
    }
    */

    /*
    - iterator 적용 혹은 미적용 버젼 둘다 할 것
    */
    template <typename T>
    class Tree
    {
    public:
        typedef T           value_type;
        typedef Node<T>*    Node_ptr; //member type
    private:
        Node_ptr    _root; //header
        size_t      _element_count;

    public:
        Tree(void);
        explicit Tree(const value_type& value);
        Tree(const Tree& org_tree);
        ~Tree();

        Tree& operator=(const Tree& org_tree);

        bool    insert(const value_type& value);
        bool    remove(const value_type& value);

        Node_ptr get_root() const;
        size_t  get_element() const;

        // Tree& search();
        // void delete(); // bool?
    };
    
    template <typename T>
    void    print_pre_order(const typename Tree<T>::Node_ptr& cur_node);

    template <typename T>
    void    print_in_order(typename Tree<T>::Node_ptr cur_node);

    template <typename T>
    void    print_post_order(const typename Tree<T>::Node_ptr& cur_node);
   /**/
    // non-member
    /*
    inorder();
    preorder();
    postorder();
    */

    template <typename T>
    inline Tree<T>::Tree(void)
        : _root(NULL), _element_count(0)
    {}

    template <typename T>
    inline Tree<T>::Tree(const value_type &value)
        : _root(new Node<T>(value)), _element_count(0)
    {}

    template <typename T>
    inline Tree<T>::Tree(const Tree &org_tree)
        : _root(org_tree.get_root()), _element_count(org_tree.get_element())
    {
        // TODO
        /*
        */
    }

    template <typename T>
    inline Tree<T>::~Tree()
    {
        // clear()
        // post-order
        //delete all
    }
    
    template <typename T>
    inline Tree<T>& Tree<T>::operator=(const Tree &org_tree)
    {
        // TODO: 여기에 return 문을 삽입합니다.
        if (this != &org_tree)
        {
            this->_node = org_tree._node;
            this->_element_count = org_tree._element_count;
        }
        return (*this);
    }
    
    template <typename T>
    inline bool Tree<T>::insert(const value_type& value)
    {
        Node_ptr    parent;

        parent = this->get_root();
        while (parent)
        {
            if (value < parent->_data)
            {
                if (parent->_left_child_node == NULL)
                {
                    parent->_left_child_node = new Node<T>(value);
                    this->_element_count++;
                    return (true);
                }
                parent = parent->_left_child_node;
            }
            else if (value > parent->_data)
            {
                if (parent->_right_child_node == NULL)
                {
                    parent->_right_child_node = new Node<T>(value);
                    this->_element_count++;
                    return (true);
                }
                parent = parent->_right_child_node;
            }
            else if (value == parent->_data)
                throw std::runtime_error("BST dose not take same value\n");
        }
        return false;
    }
    
    template <typename T>
    inline bool Tree<T>::remove(const value_type& value)
    {
        Node_ptr    cur_node;

        cur_node = this->get_root();
        while (cur_node)
        {
            if (cur_node._data == value)
            {
                // find successor
                Node_ptr    successor;
                successor = find_successor(cur_node);
                 //후손 노드가 없는 경우, 
                 //이전 노드에서 못가르키게 바꾸어야함
                if (successor == NULL)
                    cur_node
            }

            if (cur_node._data == value)
            cur_node = ;
        }
        return (false);
    }

    // Node_ptr&    find_successor()
    Node_ptr    find_successor(const Node_ptr& cur_node)
    {
        // left most, right_less
        // left_successor, right_successor
        Node_ptr    successor;
        // Node_ptr    left_side_node;
        // Node_ptr    right_side_node;
        successor = NULL;
        if (cur_node == NULL)
            return (NULL);
        successor = find_left_side_successor(cur_node->_left_child_node);
        if (successor == NULL)
            successor = find_right_side_successor(cur_node->_right_child_node);
        return (successor);
    }

    Node_ptr    find_left_side_successor(const Node_ptr& cur_node)
    {
        //biggest one of left side
        Node_ptr    successor;

        successor = cur_node;
        if (successor == NULL)
            return (NULL);
        while (successor->_right_child_node)
            successor = successor->_right_child_node;
        return (successor);
    }

    Node_ptr    find_right_side_successor(const Node_ptr& cur_node)
    {
        //smallest one of left side
        Node_ptr    successor;

        successor = cur_node;
        if (successor == NULL)
            return (NULL);
        while (successor->_left_child_node)
            successor = successor->_left_child_node;
        return (successor);
    }

    template <typename T>
    inline typename Tree<T>::Node_ptr Tree<T>::get_root() const
    {
        // TODO: 여기에 return 문을 삽입합니다.
        return (this->_root);
    }

    template <typename T>
    inline size_t Tree<T>::get_element() const
    {
        // TODO: 여기에 return 문을 삽입합니다.
        return (this->_element_count);
    }

    template <typename T>
    void print_pre_order(const typename Tree<T>::Node_ptr &cur_node)
    {
        if (cur_node == NULL)
            return ;
        std::cout << cur_node->_data<< std::endl;
        print_pre_order(cur_node->_left_child_node);
        print_pre_order(cur_node->_right_child_node);
    }
    
    template <typename T>
    void print_in_order(typename Tree<T>::Node_ptr&cur_node)
    {
        if (cur_node == NULL)
            return ;
        print_pre_order(cur_node->_left_child_node);
        std::cout << cur_node->_data<< std::endl;
        print_pre_order(cur_node->_right_child_node);
    }

    template <typename T>
    void print_post_order(const typename Tree<T>::Node_ptr &cur_node)
    {
        if (cur_node == NULL)
            return ;
        print_pre_order(cur_node->_left_child_node);
        print_pre_order(cur_node->_right_child_node);
        std::cout << cur_node->_data<< std::endl;
    }
}

#endif