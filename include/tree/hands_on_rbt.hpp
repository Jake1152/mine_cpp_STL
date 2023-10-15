#ifndef __HANDS_ON_TREE__
#define __HANDS_ON_TREE__


namespace ft
{
    typedef bool    _Rb_tree_Color_type;
    const _Rb_tree_Color_type   _S_rb_tree_red = false;
    const _Rb_tree_Color_type   _S_rb_tree_black = true;


    struct  _Rb_tree_node_base
    {};

    template <typename _Value>
    struct _Rb_tree_node : public _Rb_tree_node_base
    {};

    struct _Rb_tree_base_iteraotr
    {};

    template <typename _Value, typename _Ref, typename _Ptr>
    struct _Rb_tree_iterator : public _Rb_tree_base_iterator
    {};

    template <typename _Value, typename _Ref, typename _Ptr>
    inline bool operator==(const _Rb_tree_iterator<_Value, _Ref, _Ptr>& _x,
             const _Rb_tree_iterator<_Value, _Ref, _Ptr>& __y)
    {}

    template <typename _Value>
    inline bool operator==(const _Rb_tree_iterator<_Value, const _Value&, const _Value*>& __x, 
                const _Rb_tree_iterator<_Value, _Value&, _Value*>& __y)
    {}

    template <typename _Value>
    inline bool operator==(const _Rb_tree_iterator<_Value, _Value&, _Value*>& __x,
                const _Rb_tree_iterator<_Value, const _Value&, const _Value*>& __y)
    {}

    template <typename _Value, typename _Ref, typename _Ptr>
    inline bool operator!=(const _Rb_tree_iterator<_Value, _Ref, _Ptr>& __x,
            const _Rb_tree_iterator<_Value, _Ref, _Ptr>& __y)
    {}

    template <typename _Value>
    inline bool operator!=(const _Rb_tree_iterator<_Value, const _Value&, const _Value*>& __x,
            const _Rb_tree_iterator<_Value, _Value&, _Value*>& __y)
    {}

    inline void _Rb_tree_rotate_left(_Rb_tree_node_base* __x, _Rb_tree_node_base*& __root)
    {}

    inline void _Rb_tree_rotate_right(_Rb_tree_node_base* __x, _Rb_tree_node_base*& __root)
    {}

    inline void _Rb_tree_rebalance(_Rb_tree_node_base* __x, _Rb_tree_node_base*& __root)
    {}

    inline void _Rb_tree_rebalance_for_erase*(_Rb_tree_node_base* __z,
                                    _Rb_tree_node_base*& __root,
                                    _Rb_tree_node_base*& __leftmost,
                                    _Rb_tree_node_base*& __rightmost)
    {}

    template <typename _Tp, typename _Alloc, bool _S_instanceless>
    class _Rb_tree_alloc_base
    {};

    /*
        true인 이유
    */
    template <typename _Tp, typename _Alloc>
    class _Rb_tree_alloc_base<_Tp, _Alloc, true>
    {};

    template <typename _Tp, typename _Alloc>
    struct _Rb_tree_base
    {};

    template <typename _Key, typename _Value, tpyename _KeyOfValue, typename _Compare,
                typename _Alloc = allocator<_Value> >
    class _Rb_tree : protected _Rb_tree_base<_Value, _Alloc>
    {};

    template <typename _Key, typename _Value, typename _KeyoOfValue, typename _Compare,
                typenmae _Alloc>
    inline bool operator==(const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __x,
                            const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __y)
    {}

    template <typename _Key, typename _Value, typename _KeyoOfValue, typename _Compare,
                typenmae _Alloc>
    inline bool operator!=(const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __x,
                            const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __y)
    {}

    template <typename _Key, typename _Value, typename _KeyoOfValue, typename _Compare,
                typenmae _Alloc>
    inline bool operator<(const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __x,
                            const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __y)
    {}

    template <typename _Key, typename _Value, typename _KeyoOfValue, typename _Compare,
                typenmae _Alloc>
    inline bool operator<=(const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __x,
                            const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __y)
    {}

    template <typename _Key, typename _Value, typename _KeyoOfValue, typename _Compare,
                typenmae _Alloc>
    inline bool operator>(const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __x,
                            const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __y)
    {}

    template <typename _Key, typename _Value, typename _KeyoOfValue, typename _Compare,
                typenmae _Alloc>
    inline bool operator>=(const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __x,
                            const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __y)
    {}

    template <typename _Key, typename _Value, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
    inline void swap(_Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __x,
                    _Rb_tree<_Key, _Value, _KeyofValue, _Compare, _Alloc>& __y)
    {}

    template <typename _Key, typename _Value, typename _KeyOfValue,
                typename _Compare, typename _Alloc>
    _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>&
    _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>
    ::operator=(const _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>& __x)
    {}

    template <typename _Key, typename _Value, typename _KeyOfValue,
            typename _Compare, typename _Alloc>
    typename _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iteraotr    
    _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>   ::_M_insert(_Base_ptr __x_, _Base_Ptr __y_, const Value& __v)
    {}

    template <typename _Key, typename _Value, typename _KeyOfValue,
                typename _Compare, typename _Alloc>
    typename _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator    
    ::insert_equal(const _Value& __v)
    {}

    template <typename _Key, typename _Value, typename _KeyOfValue,
                typename _Compare, typename _Alloc>
    pair<typename _Rb_tree<_Key, _Value, _KeyOfValue, _Compare, _Alloc>::iterator, bool>    
    ::insert_unique(const _Value& __v)
    {}


}


#endif