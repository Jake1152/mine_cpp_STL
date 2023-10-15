#include <iostream>
// #include "../../include/tree/binary_search_tree.hpp"
#include "../../include/avl_tree.hpp"
// #include "../../include/tree/avl_tree_no_parent_node.hpp"
// #include "../../include/utility.hpp"
// #include "../../include/tree/avl_tree_with_parent.hpp"
#include <string>
#include <utility>

void    test()
{
    system("leaks bst_node_00");
}

// template <typename Key, typename Value>
// void    test_parent(ft::avl_tree<Key, Value> tree)
// {
//      if (tree.get_parent(tree.get_root()) == NULL)
//         std::cout << "tree.get_parent(tree.get_root()) is NULL" << std::endl;
//     else
//         std::cout << "tree.get_parent(tree.get_root())->_value : " << tree.get_parent(tree.get_root())->_value << std::endl;

//     if (tree.get_parent(tree.find(42)) == NULL)
//         std::cout << "tree.get_parent(tree.find(42)) is NULL" << std::endl;
//     else
//         std::cout << "tree.get_parent(tree.find(42))->_value : " << tree.get_parent(tree.find(42))->_value << std::endl;

//     if (tree.get_parent(tree.find(45)) == NULL)
//         std::cout << "tree.get_parent(tree.find(45)) is NULL" << std::endl;
//     else
//         std::cout << "tree.get_parent(tree.find(45))->_value : " << tree.get_parent(tree.find(45))->_value << std::endl;

//     if (tree.get_parent(tree.find(40)) == NULL)
//         std::cout << "tree.get_parent(tree.find(40)) is NULL" << std::endl;
//     else
//         std::cout << "tree.get_parent(tree.find(40))->_value : " << tree.get_parent(tree.find(40))->_value << std::endl;

//     if (tree.get_parent(tree.find(39)) == NULL)
//         std::cout << "tree.get_parent(tree.find(39)) is NULL" << std::endl;
//     else
//         std::cout << "tree.get_parent(tree.find(39))->_value : " << tree.get_parent(tree.find(39))->_value << std::endl;

//     if (tree.get_parent(tree.find(1152)) == NULL)
//         std::cout << "tree.get_parent(tree.find(1152)) is NULL" << std::endl;
//     else
//         std::cout << "tree.get_parent(tree.find(1152))->_value : " << tree.get_parent(tree.find(1152))->_value << std::endl;
// }

int main()
{
    
    
   /* */
    std::cout << "============== binary_search_tree Node ==============" << std::endl;
    // ft::node<int>    node;
    // ft::node<int, int>    node(42, 1152);
    // if (node._left == NULL)
    //     std::cout << "left child node is NULL" << std::endl;
    // if (node._right == NULL)
    //     std::cout << "right child node is NULL" << std::endl;
    // std::cout << "data is " << node._value.first << std::endl;
    // std::cout << std::endl;
    std::cout << "============== avl_tree ==============" << std::endl;
    ft::avl_tree<int, std::string>   tree;
    // ft::avl_tree<int, int>::node_ptr cur_node;
    // ft::avl_tree<int>   tree(42);

    if (tree.get_root() == NULL)
        std::cout << "tree _root is NULL" << std::endl;
    else
        std::cout << "tree _root first : " << tree.get_root()->_value.first << "second : " << tree.get_root()->_value.second << std::endl;

    // tree.insert(ft::make_pair(152, 3));
    // tree.erase(1152);
    std::cout << "## tree.size() : " << tree.size() << std::endl;
    
    tree.insert(ft::make_pair(42, "lol"));

	tree.insert(ft::make_pair(50, "mdr"));
	tree.insert(ft::make_pair(25, "funny"));

	tree.insert(ft::make_pair(46, "bunny"));
	tree.insert(ft::make_pair(21, "fizz"));
	tree.insert(ft::make_pair(30, "buzz"));
	tree.insert(ft::make_pair(55, "fuzzy"));

	tree.insert(ft::make_pair(18, "bee"));
	tree.insert(ft::make_pair(23, "coconut"));
	tree.insert(ft::make_pair(28, "diary"));
	tree.insert(ft::make_pair(35, "fiesta"));
	tree.insert(ft::make_pair(44, "hello"));
	tree.insert(ft::make_pair(48, "world"));
	tree.insert(ft::make_pair(53, "this is a test"));
	tree.insert(ft::make_pair(80, "hey"));

	tree.insert(ft::make_pair(12, "no"));
	tree.insert(ft::make_pair(20, "idea"));
	tree.insert(ft::make_pair(22, "123"));
	tree.insert(ft::make_pair(24, "345"));
	tree.insert(ft::make_pair(27, "27"));
	tree.insert(ft::make_pair(29, "29"));
	tree.insert(ft::make_pair(33, "33"));
	tree.insert(ft::make_pair(38, "38"));

	tree.insert(ft::make_pair(43, "1"));
	tree.insert(ft::make_pair(45, "2"));
	tree.insert(ft::make_pair(47, "3"));
	tree.insert(ft::make_pair(49, "4"));
	tree.insert(ft::make_pair(51, "5"));
	tree.insert(ft::make_pair(54, "6"));
	tree.insert(ft::make_pair(60, "7"));
	tree.insert(ft::make_pair(90, "8"));
    // tree.insert(ft::make_pair(600, 3));
    std::cout << "## tree.size() : " << tree.size() << std::endl;
    // map
    // // // test_parent(tree);
    tree.erase(25);
    tree.erase(55);
    tree.erase(24);
    tree.erase(54);

    tree.erase(22);
    tree.erase(51);
    tree.erase(21);
    tree.erase(53);

    tree.erase(20);
    tree.erase(23);
    tree.erase(42);
    tree.erase(38);

    tree.erase(35);
    tree.erase(33);

    // tree.insert(ft::make_pair(40, 3));
    // tree.insert(ft::make_pair(39, 3));
    // tree.insert(ft::make_pair(2, 3));
    
    // tree.insert(ft::make_pair(4, 3));
    // tree.insert(ft::make_pair(1, 3));
    // tree.insert(ft::make_pair(44, 3));
    // tree.insert(ft::make_pair(424, 3));
    // tree.insert(ft::make_pair(420, 3));
    
    // tree.insert(ft::make_pair(430, 3));
    // tree.insert(ft::make_pair(427, 3));
    // tree.insert(ft::make_pair(429, 3));
    // std::cout << "## tree.size() : " << tree.size() << std::endl;
    // // tree.insert(ft::make_pair(433, 3));

    // tree.print_tree();

    // // // # find
    // // // cur_node = tree.find(42);
    // // // std::cout << std::endl;
    // // // std::cout << "try to find " << 42 << std::endl;
    // // // if (cur_node)
    // // //     std::cout << cur_node->_value.first << std::endl;
    // // // std::cout << std::endl;
    
    // // // if (tree.get_parent(tree.find(2)))
    // // //     std::cout << "tree.get_parent(tree.find(2))->_value.first : " << tree.get_parent(tree.find(2))->_value.first << std::endl;

    // // // ft::avl_tree<int, int>::node_ptr successor;

    // // // successor = tree.find_successor(tree.find(2));
    // // // if (successor)
    // // //     std::cout << "successor->_value.first : " << successor->_value.first << std::endl;

    // // // if (tree.get_parent(tree.find(1)))
    // // //     std::cout << "tree.get_parent(tree.find(1))->_value.first : " << tree.get_parent(tree.find(1))->_value.first << std::endl;
    // tree.erase(44);
    // tree.erase(140);
    // tree.erase(442);
    // tree.erase(38);

    // // tree.erase(39);
    // tree.erase(39);
    // tree.erase(430);
    // tree.erase(42);
    // tree.erase(424);
    // // // std::cout << "## after erase(42) tree.size()  : " << tree.size() << std::endl;
    // tree.erase(152);
    // tree.erase(150);

    // tree.erase(1);
    // tree.erase(600);
    // tree.erase(542);
    // // tree.print_tree();
    // // tree.insert(ft::make_pair(2, 3));
    // // tree.insert(ft::make_pair(42, 3));
    // // tree.insert(ft::make_pair(2, 3));
    
    // tree.erase(4);
    // tree.erase(40);
    // tree.erase(427);
    // tree.erase(429);
    // tree.erase(642);
    // tree.erase(420);
    // tree.erase(342);
    // tree.erase(342);
    // // tree.print_tree();
    // tree.erase(242);
    // // tree.print_tree();
    // // ft::avl_tree<int, int> tree_copy(tree);
    // // tree_copy.print_tree();

    // // std::cout << "tree.get_root()" << tree.get_root()->_value<< std::endl;
    // // ft::avl_tree<int>::node_ptr    find_node;
    // // find_node = tree.find(1152);
    // // std::cout << find_node->_value<< std::endl;
    // // ft::Node<int>::Node_ptr cur_node;
    // // if (tree.get_root() && tree.get_root()->_left)
    // //     cur_node = tree.get_root()->_left;
    // // else if (tree.get_root() && tree.get_root()->_right)
    // //     cur_node = tree.get_root()->_right;
    // // std::cout << "cur_node._value : " << cur_node->_value << std::endl;
    // // // ft::print_post_order(tree.get_root());
    // // ft::print_in_order(tree.get_root());
    // tree.erase(425);
    // tree.print_tree();
    // tree.erase(424);
    // tree.erase(44);
    // tree.erase(2);
    // // tree.erase(4);
    // tree.print_tree();
    std::cout << "tree.size() : " << tree.size() << std::endl;
    // tree.clear();
    tree.print_tree();
    std::cout << "tree.size() : " << tree.size() << std::endl;
    std::cout << std::endl;
    // system("leaks benchmark");
    atexit(test);
    
    return (0);
}
