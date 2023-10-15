#ifndef __RED_BLACK_TREE_HPP__
#define __RED_BLACK_TREE_HPP__

#define BLACK true
#define RED false

struct red_black_tree_base
{
public:
    typedef red_black_tree_base*    rbt_base_ptr;
    bool            _color;
    rbt_base_ptr    _parent;
    rbt_base_ptr    _left_child;
    rbt_base_ptr    _right_child;
};

template <typename value_type>
struct red_black_tree : public red_black_tree_base
{
    // value_type  
};


#endif