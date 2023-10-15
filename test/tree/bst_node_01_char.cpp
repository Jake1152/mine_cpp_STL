#include <iostream>
// #include "../../include/tree/binary_search_tree.hpp"
#include "../../include/tree/avl_tree.hpp"
// #include "../../include/tree/avl_tree_with_parent.hpp"
#include <string>

void    test()
{
    system("leaks bst_node_00");
}

template <typename T>
void    test_parent(ft::avl_tree<T> tree)
{
     if (tree.get_parent(tree.get_root()) == NULL)
        std::cout << "tree.get_parent(tree.get_root()) is NULL" << std::endl;
    else
        std::cout << "tree.get_parent(tree.get_root())->_value : " << tree.get_parent(tree.get_root())->_value << std::endl;

    if (tree.get_parent(tree.find(42)) == NULL)
        std::cout << "tree.get_parent(tree.find(42)) is NULL" << std::endl;
    else
        std::cout << "tree.get_parent(tree.find(42))->_value : " << tree.get_parent(tree.find(42))->_value << std::endl;

    if (tree.get_parent(tree.find(45)) == NULL)
        std::cout << "tree.get_parent(tree.find(45)) is NULL" << std::endl;
    else
        std::cout << "tree.get_parent(tree.find(45))->_value : " << tree.get_parent(tree.find(45))->_value << std::endl;

    if (tree.get_parent(tree.find(40)) == NULL)
        std::cout << "tree.get_parent(tree.find(40)) is NULL" << std::endl;
    else
        std::cout << "tree.get_parent(tree.find(40))->_value : " << tree.get_parent(tree.find(40))->_value << std::endl;

    if (tree.get_parent(tree.find(39)) == NULL)
        std::cout << "tree.get_parent(tree.find(39)) is NULL" << std::endl;
    else
        std::cout << "tree.get_parent(tree.find(39))->_value : " << tree.get_parent(tree.find(39))->_value << std::endl;

    if (tree.get_parent(tree.find(1152)) == NULL)
        std::cout << "tree.get_parent(tree.find(1152)) is NULL" << std::endl;
    else
        std::cout << "tree.get_parent(tree.find(1152))->_value : " << tree.get_parent(tree.find(1152))->_value << std::endl;
}

int main()
{
    std::cout << "============== binary_search_tree Node ==============" << std::endl;
    // ft::node<char>    node;
    ft::node<char>    node('h');
    if (node._left == NULL)
        std::cout << "left child node is NULL" << std::endl;
    if (node._right == NULL)
        std::cout << "right child node is NULL" << std::endl;
    std::cout << "data is " << node._value << std::endl;
    // std::cout << std::endl;

    std::cout << "============== avl_tree ==============" << std::endl;
    ft::avl_tree<char>   tree;
    // ft::avl_tree<char>::node_ptr cur_node;
    // ft::avl_tree<char>   tree(42);

    if (tree.get_root() == NULL)
        std::cout << "tree _root is NULL" << std::endl;
    else
        std::cout << "tree _root is " << tree.get_root()->_value << std::endl;
    // if (tree.get_root() == NULL)
    //     std::cout << "tree _root is NULL" << std::endl;
    // else
    //     std::cout << "tree _root is " << tree.get_root()->_value << std::endl;
    // if (tree.get_root() == NULL)
    //     std::cout << "tree _root is NULL" << std::endl;
    // else
    // {
    //     cur_node = tree.get_root()->_left;
    //     if (cur_node)
    //         std::cout << "tree left child is " << cur_node->_value << std::endl;
    // }
    tree.insert('b');
    tree.insert('c');
    tree.insert('z');
    tree.insert('j');
    tree.insert('i');
    // test_parent(tree);

    // tree.insert('m');
    // tree.insert('e');
    // tree.insert(4); 
    // tree.insert(1);
    // tree.insert(44);
    // tree.insert(41);
    // tree.insert(423);
    // tree.insert(424);
    // tree.insert(425);

    // tree.insert(4); 
    // tree.insert(1);
    tree.print_tree();
    // tree.get_height(tree.get_root());
    std::cout << "tree.get_height(tree.get_root()) : " << tree.get_height(tree.get_root()) << std::endl;
    std::cout << "tree.get_balance_factor(tree.get_root()); : " << tree.get_balance_factor(tree.get_root()) << std::endl;
    // cur_node->_value = 442;
    // tree.print_tree();
    // cur_node = tree.find(42);
    // std::cout << "try to find " << 42 << std::endl;
    // if (cur_node)
    //     std::cout << cur_node->_value << std::endl;
    // tree.erase(42);
    // tree.erase('z');
    // tree.print_tree();
    tree.erase('c');
    tree.erase('j');
    // tree.print_tree();
    tree.erase('i');
    // tree.erase('b');
    // test_parent(tree);

    tree.erase('m');
    tree.erase('e');

    // tree.erase(4);
    // // tree.print_tree();
    // tree.insert(4);
    tree.insert('a');
    tree.insert('i');
    // tree.erase(425);
    // tree.erase(424);
    // tree.erase(45);
    tree.print_tree();

    // std::cout << "tree.get_root()" << tree.get_root()->_value<< std::endl;
    // ft::avl_tree<char>::node_ptr    find_node;
    // find_node = tree.find(1152);
    // std::cout << find_node->_value<< std::endl;
    // ft::Node<char>::Node_ptr cur_node;
    // if (tree.get_root() && tree.get_root()->_left)
    //     cur_node = tree.get_root()->_left;
    // else if (tree.get_root() && tree.get_root()->_right)
    //     cur_node = tree.get_root()->_right;
    // std::cout << "cur_node._value : " << cur_node->_value << std::endl;
    // // ft::print_post_order(tree.get_root());
    // ft::print_in_order(tree.get_root());
    // system();
    std::cout << std::endl;
    // system("leaks benchmark");
    // atexit(test);
    return (0);
}
