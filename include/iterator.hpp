#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

#include "iterator_traits.hpp"

namespace ft
{
    template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
    struct iterator {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };

    /*
        - random access iterator 구현에 대한 나만의 생각
        이것의 역할은 무엇인가
        그 역할을 위해 구체적으로 필요한 것들은 무엇인가
        그 역할을 원활하게 되게하기 위해서 어떤식으로 구현해주는 것이 좋을 것인가?

        - iterator에 iterator_traits를 통해서 처리하게 하였으며
        traits에 template specialization등으로 T, T*까지의 케이스들도 처리하게 하였으모
        직접 내가 정의하는 것보다 활용하는 것이 traits가 있는 의미를 살릴수 있다고 판단
        difference_type, reference, pointer 같은 축약된 이름으로 바로 쓸 수 없으니
        typedef 하여 쓸수 있게 한다.
    */
    template<typename T>
    class random_access_iterator
        : public iterator<typename ft::iterator_traits<T *>::iterator_category,
                        typename ft::iterator_traits<T *>::value_type,
                        typename ft::iterator_traits<T *>::difference_type,
                        typename ft::iterator_traits<T *>::pointer,
                        typename ft::iterator_traits<T *>::reference>
    {
    public:
        typedef          T*                                                 Iterator;
        typedef          Iterator                                           iterator_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename ft::iterator_traits<Iterator>::reference           reference;
        typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
        typedef typename ft::iterator_traits<Iterator>::value_type          value_type;

    private:
        Iterator    _current;

    public:

        random_access_iterator();
        explicit random_access_iterator(Iterator iter); // const Iterator& iter 로 한다면  random_access_iterator와 구분은 어떻게 할것인가?
        template <typename Iter>
        random_access_iterator(const random_access_iterator<Iter>& org_iter);
        virtual ~random_access_iterator();
        
        random_access_iterator& operator=(const random_access_iterator& org_random_access_iterator);

        iterator_type   base() const;
        reference operator*() const;
        random_access_iterator operator+ (difference_type n) const;
        random_access_iterator& operator++();
        random_access_iterator  operator++(int);
        random_access_iterator& operator+= (difference_type n);
        random_access_iterator operator- (difference_type n) const;
        random_access_iterator& operator--();
        random_access_iterator  operator--(int);
        random_access_iterator& operator-= (difference_type n);
        pointer operator->() const;
        reference operator[] (difference_type n) const;
    };
    // (1)	
    template <typename Iterator1, typename Iterator2>
    bool operator== (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs);
    // (2)	
    template <typename Iterator1, typename Iterator2>
    bool operator!= (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs);
    // (3)	
    template <typename Iterator1, typename Iterator2>
    bool operator<  (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs);
    // (4)	
    template <typename Iterator1, typename Iterator2>
    bool operator<= (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs);
    // (5)	
    template <typename Iterator1, typename Iterator2>
    bool operator>  (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs);
    // (6)Iterator
    template <typename Iterator1, typename Iterator2>
    bool operator>= (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs);

    template <typename Iterator>
    typename random_access_iterator<Iterator>::difference_type    operator- (const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs);

    template <typename Iterator1, typename Iterator2>
    typename random_access_iterator<Iterator1>::difference_type    operator- (const random_access_iterator<Iterator1>& lhs, const random_access_iterator<Iterator2>& rhs);
    
    template <typename Iterator>
    random_access_iterator<Iterator>  operator+ ( typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator>& random_it);

    template <typename Iterator1, typename Iterator2>
    random_access_iterator<Iterator1>  operator+ ( typename random_access_iterator<Iterator1>::difference_type n, const random_access_iterator<Iterator2>& random_it);
    /*
        ---------------------------------
        --define random access iterator--
        ---------------------------------
    */
    template <typename T>
    inline random_access_iterator<T>::random_access_iterator()
        : _current(NULL)
    {}
    
    // TODO
    template <typename T>
    inline random_access_iterator<T>::random_access_iterator(Iterator iter)
        : _current(iter)
    {}

    template <typename T>
    template <typename Iter>
    inline random_access_iterator<T>::random_access_iterator(const random_access_iterator<Iter>& org)
        : _current(org.base())
    {}

    template <typename T>
    inline random_access_iterator<T>::~random_access_iterator()
    {}


    template <typename T>
    inline random_access_iterator<T>& random_access_iterator<T>::operator=(const random_access_iterator& org_random_access_iterator)
    {
        if (this != &org_random_access_iterator)
            this->_current = org_random_access_iterator._current;
        return (*this);
    }

    template <typename T>
    inline typename random_access_iterator<T>::iterator_type random_access_iterator<T>::base() const
    {
        return (this->_current);
    }

    template <typename T>
    inline typename random_access_iterator<T>::reference random_access_iterator<T>::operator*() const
    {
        return (*(this->_current));
    }

    template <typename T>
    inline random_access_iterator<T> random_access_iterator<T>::operator+(difference_type n) const
    {
        return (random_access_iterator(this->_current + n));
    }

    template <typename T>
    inline random_access_iterator<T>& random_access_iterator<T>::operator++()
    {
        this->_current++;
        return (*this);
    }

    template <typename T>
    inline random_access_iterator<T> random_access_iterator<T>::operator++(int)
    {
        random_access_iterator  prev_random_access_iterator(*this);
        this->_current++;
        return prev_random_access_iterator;
    }

    template <typename T>
    inline random_access_iterator<T> &random_access_iterator<T>::operator+=(difference_type n)
    {
        this->_current += n;
        return (*this);
    }

    template <typename T>
    inline random_access_iterator<T> random_access_iterator<T>::operator- (difference_type n) const
    {
        return (random_access_iterator(this->_current - n));
    }

    template <typename T>
    inline random_access_iterator<T> &random_access_iterator<T>::operator--()
    {
        this->_current--;
        return (*this);
    }

    template <typename T>
    inline random_access_iterator<T> random_access_iterator<T>::operator--(int)
    {
        random_access_iterator  prev_random_access_iterator(*this);
        this->_current--;
        return prev_random_access_iterator;
    }

    template <typename T>
    inline random_access_iterator<T> &random_access_iterator<T>::operator-=(difference_type n)
    {
        this->_current -= n;
        return (*this);
    }

    template <typename T>
    inline typename random_access_iterator<T>::pointer random_access_iterator<T>::operator->() const
    {
        // return (&(this->_current)) 차이점은 무엇인가? 안정성이 높은가? 
        return (&(operator*()));
    }

    template <typename T>
    inline typename random_access_iterator<T>::reference random_access_iterator<T>::operator[](difference_type n) const
    {
        return (*(this->_current + n));
    }

        template <typename Iterator1, typename Iterator2>
    bool operator==(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    bool operator!=(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <typename Iterator1, typename Iterator2>
    bool operator<(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
    {
        // TODO base로 비교하는 것이 맞는가 검증 필요
        return (lhs.base() < rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    bool operator<=(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
    {
        return (!(rhs < lhs));
    }

    template <typename Iterator1, typename Iterator2>
    bool operator>(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
    {
        return (rhs < lhs);
    }

    template <typename Iterator1, typename Iterator2>
    bool operator>=(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
    {
        return (!(lhs < rhs));
    }

    template <typename Iterator>
    random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator<Iterator> &random_it)
    {
        return (random_access_iterator<Iterator>(random_it + n));
    }

    template <typename Iterator1, typename Iterator2>
    random_access_iterator<Iterator1> operator+(typename random_access_iterator<Iterator1>::difference_type n, const random_access_iterator<Iterator2> &random_it)
    {
        return (random_access_iterator<Iterator1>(random_it + n));
    }

    template <typename Iterator>
    typename random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
    {
        return (lhs.base() - rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    typename random_access_iterator<Iterator1>::difference_type operator-(const random_access_iterator<Iterator1> &lhs, const random_access_iterator<Iterator2> &rhs)
    {
        return (lhs.base() - rhs.base());
    }


    /*
        -------------------------------
        -------reverse_iterator--------
        -------------------------------
    */
    template<typename Iterator>
    class reverse_iterator
    {
    private:
        Iterator    _current;
    
    public:
        typedef          Iterator                                           iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

        // default (1)	
        reverse_iterator();
        // initialization (2)	
        explicit reverse_iterator (iterator_type it);
        // copy (3)	
        template <typename Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it);

        reverse_iterator& operator=(const reverse_iterator& org_reverse_iterator);

        iterator_type base() const;
        reference operator*() const;
        reverse_iterator operator+ (difference_type n) const;
        reverse_iterator& operator++();
        reverse_iterator  operator++(int);
        reverse_iterator& operator+= (difference_type n);
        reverse_iterator operator- (difference_type n) const;
        reverse_iterator& operator--();
        reverse_iterator  operator--(int);
        reverse_iterator& operator-= (difference_type n);
        pointer operator->() const;
        reference operator[] (difference_type n) const;
    };

    // (1)	
    template <class Iterator1, class Iterator2>
    bool operator== (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
    // (2)	
    template <class Iterator1, class Iterator2>
    bool operator!= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
    // (3)	
    template <class Iterator1, class Iterator2>
    bool operator<  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
    // (4)	
    template <class Iterator1, class Iterator2>
    bool operator<= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
    // (5)	
    template <class Iterator1, class Iterator2>
    bool operator>  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
    // (6)	
    template <class Iterator1, class Iterator2>
    bool operator>= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type    operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

    template <class Iterator1, class Iterator2>
    typename reverse_iterator<Iterator1>::difference_type    operator- (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs);
    
    template <class Iterator1, class Iterator2>
    reverse_iterator<Iterator1>  operator+ ( typename reverse_iterator<Iterator1>::difference_type n, const reverse_iterator<Iterator2>& rev_it);

    template <typename Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it);

    /*
        ------------------------------
        --define reverse iterator------
        ------------------------------
    */
    template <typename Iterator>
    inline reverse_iterator<Iterator>::reverse_iterator()
        :_current()
    {}

    template <typename Iterator>
    inline reverse_iterator<Iterator>::reverse_iterator(iterator_type it)
        :_current(it)
    {}

    template <typename Iterator>
    template <typename Iter>
    inline reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<Iter>& rev_it)
        : _current(rev_it.base())
    {}

    template <typename Iterator>
    inline reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator=(const reverse_iterator<Iterator>& org_reverse_iterator)
    {
        if (this != &org_reverse_iterator)
            this->_current = org_reverse_iterator.base();
        return (*this);
    }

    template <typename Iterator>
    inline typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const
    {
        return (this->_current);
    }

    template <typename Iterator>
    inline typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const
    {
        iterator_type   deference_iter;

        deference_iter = this->_current;
        deference_iter--;
        return (*deference_iter);
    }

    template <typename Iterator>
    inline reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+ (difference_type n) const
    {
        return (reverse_iterator((this->_current) - n));
    }

    template <typename Iterator>
    inline reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator++()
    {
        this->_current--;
        return (*this);
    }
    
    template <typename Iterator>
    inline reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int)
    {
        reverse_iterator    org_reverse_iterator(this->_current);
        this->_current--;
        return (org_reverse_iterator);
    }

    template <typename Iterator>
    inline reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator+= (difference_type n)
    {
        this->_current -= n;
        return (*this);
    }

    template <typename Iterator>
    inline reverse_iterator<Iterator> reverse_iterator<Iterator>::operator- (difference_type n) const
    {
        return (reverse_iterator(this->_current + n));
    }

    template <typename Iterator>
    inline reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator--()
    {
        this->_current++;
        return (*this);

    }

    template <typename Iterator>
    inline reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int)
    {
        reverse_iterator    org_reverse_iterator(this->_current);
        this->_current++;
        return (org_reverse_iterator);
    }

    template <typename Iterator>
    inline reverse_iterator<Iterator>& reverse_iterator<Iterator>::operator-= (difference_type n)
    {
        this->_current += n;
        return (*this);
    }

    template <typename Iterator>
    inline typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const
    {
        // TODO
        // return &(operator*()); 차이점은?
        // return (&(this->_current));
        return &(operator*());
    }

    template <typename Iterator>
    inline typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[] (difference_type n) const
    {
        // e.g) *(rbegin + n)
        return *(*this + n);
    }
    

    template <typename Iterator1, typename Iterator2>
    bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    bool operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (!(lhs == rhs));
    }
    
    template <typename Iterator1, typename Iterator2>
    bool operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        // TODO check base or value
        return (rhs.base() < lhs.base());
    }

    template <typename Iterator1, typename Iterator2>
    bool operator<= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return (!(rhs < lhs));
    }
    // (5)	
    template <typename Iterator1, typename Iterator2>
    bool operator>  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return (rhs < lhs);
    }
    // (6)	
    template <typename Iterator1, typename Iterator2>
    bool operator>= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
    {
        return (!(lhs < rhs));
    }
    
    template <typename Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return typename reverse_iterator<Iterator>::difference_type(rhs.base() - lhs.base());
    }


    template <typename Iterator1, typename Iterator2>
    typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return typename reverse_iterator<Iterator1>::difference_type(rhs.base() - lhs.base());
    }

    template <typename Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
    {
        return reverse_iterator<Iterator>(rev_it + n);
    }
    
    template <typename Iterator1, typename Iterator2>
    reverse_iterator<Iterator1> operator+(typename reverse_iterator<Iterator1>::difference_type n, const reverse_iterator<Iterator2> &rev_it)
    {
        return reverse_iterator<Iterator1>(rev_it + n);
    }

}

#endif