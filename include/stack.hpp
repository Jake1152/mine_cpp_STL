#ifndef __STACK_HPP__
#define __STACK_HPP__
#include "vector.hpp"

namespace ft
{
    template <typename T, typename Container = ft::vector<T> >
    class stack
    {
    protected:
        Container c;

    public:
        // member types
        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef typename Container::reference reference;
        typedef typename Container::const_reference const_reference;

        // # member functions
        // ## construct, destruct
        explicit stack(const Container& cont = Container());

        virtual ~stack();
        
        // ## access 
        reference top();
        const_reference top() const;

        // ## capacity
        bool empty() const;
        size_type size() const;
        
        // ## Modifiers
        void push(const value_type& value);
        void pop();

        // friend non-member operator
        template<typename _nT, typename _nContainer>
        friend bool operator==(const stack<_nT, _nContainer>& x,
                    const stack<_nT, _nContainer>& y );
        template< typename _nT, typename _nContainer >
        friend bool operator<(const stack<_nT, _nContainer>& x,
                    const stack<_nT, _nContainer>& y );
    };

    template <typename T, typename Container>
    inline stack<T, Container>::stack(const Container &cont)
        : c(cont)
    {}

    template <typename T, typename Container>
    inline stack<T, Container>::~stack()
    {}

    // ## access
    template <typename T, typename Container> 
    inline typename stack<T, Container>::reference stack<T, Container>::top()
    {
        return (c.back());
    }

    template <typename T, typename Container> 
    inline typename stack<T, Container>::const_reference stack<T, Container>::top() const
    {
        return (c.back());
    }

    // ## capacity
    template <typename T, typename Container>
    inline bool stack<T, Container>::empty() const
    {
        return (c.empty());
    }

    template <typename T, typename Container>
    inline typename stack<T, Container>::size_type stack<T, Container>::size() const 
    {
        return (c.size());
    }

    // ## Modifiers
    template <typename T, typename Container>
    inline void stack<T, Container>::push(const value_type& value)
    {
        c.push_back(value);
    }
    
    template <typename T, typename Container>
    inline void stack<T, Container>::pop(void)
    {
        c.pop_back();
    }

    // ## non-member functions
    template<typename _nT, typename _nContainer>
    inline bool operator==(const stack<_nT, _nContainer>& x,
                    const stack<_nT, _nContainer>& y )
    {
        return (x.c == y.c);
    }

    template<typename _nT, typename _nContainer>
    inline bool operator!=(const stack<_nT, _nContainer>& x,
                    const stack<_nT, _nContainer>& y )
    {
        return (!(x == y));
    }

    template<typename _nT, typename _nContainer>
    inline bool operator< (const stack<_nT, _nContainer>& x,
                    const stack<_nT, _nContainer>& y )
    {
        return (x.c < y.c);
    }

    template<typename _nT, typename _nContainer>
    inline bool operator<=(const stack<_nT, _nContainer>& x,
                    const stack<_nT, _nContainer>& y )
    {
        return (!(y < x));
    }

    template<typename _nT, typename _nContainer>
    inline bool operator> (const stack<_nT, _nContainer>& x,
                    const stack<_nT, _nContainer>& y )
    {
        return (y < x);
    }

    template<typename _nT, typename _nContainer>
    inline bool operator>=(const stack<_nT, _nContainer>& x,
                    const stack<_nT, _nContainer>& y )
    {
        return (!(x < y));
    }
}

#endif