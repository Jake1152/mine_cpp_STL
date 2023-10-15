#ifndef __UITILITY_HPP__
#define __UITILITY_HPP__

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
    public:
        typedef T1   first_type;
        typedef T2   second_type;

        first_type  first;
        second_type  second;
        // default (1)
        pair();
        // copy (2)	
        template<class U, class V>
        pair (const pair<U,V>& pr);
        // initialization (3)
        pair (const first_type& a, const second_type& b);
        ~pair();

        pair& operator=(const pair& pr);
    };

    // (1)	
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
    // (2)	
    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
    // (3)	
    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
    // (4)	
    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
    // (5)	
    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);
    // (6)	
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs);

    template <class T1, class T2>
    pair<T1,T2> make_pair (T1 lhs, T2 rhs);

    /*
        -------------------------------------------
        --Define-----------------------------------
        -------------------------------------------
    */
    template <class T1, class T2>
    inline bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    inline bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!((lhs == rhs)));
    }

    template <class T1, class T2>
    inline bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (lhs.first < rhs.first && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    inline bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!(rhs < lhs));
    }

    template <class T1, class T2>
    inline bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (rhs > lhs);
    }

    template <class T1, class T2>
    inline bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return (!(lhs < rhs));
    }

    template <class T1,class T2>
    inline pair<T1, T2> make_pair(T1 lhs, T2 rhs)
    {
        return (pair<T1, T2>(lhs, rhs));
    }

    template <class T1, class T2>
    inline pair<T1, T2>::pair()
        : first(T1()), second(T2())
    {}

    template <class T1, class T2>
    template<class U, class V>
    inline pair<T1, T2>::pair (const pair<U, V>& pr)
        : first(pr.first), second(pr.second)
    {}

    template <class T1, class T2>
    inline pair<T1, T2>::pair(const first_type &a, const second_type &b)
        : first(a), second(b)
    {}

    template <class T1, class T2>
    inline pair<T1, T2>::~pair()
    {}

    /*
        - first, second type이 동적할당 되었을 가능성을 어떻게 처리하는가?
        - pointer에 대해 enable_if를 쓴다?
    */
    template <class T1, class T2>
    inline pair<T1, T2>& pair<T1, T2>::operator=(const pair<T1, T2>& pr)
    {
        if (this != &pr)
        {
            this->first = pr.first;
            this->second = pr.second;
        }
        return (*this);
    }
}

#endif

