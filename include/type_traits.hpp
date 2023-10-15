#ifndef __TYPE_TRAITS_HPP__
#define __TYPE_TRAITS_HPP__


namespace ft
{
    template<bool Cond, typename T = void>
    struct enable_if
    {};

    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template<typename T, T val>
    struct integral_constant
    {
        static const T                      value = val;
        typedef T                           value_type;
        typedef integral_constant<T, val>   type;
        // const operator value_type() const;
        operator value_type() const;
    };

    template<typename T, T val>
    const T integral_constant<T, val>::value;

    /// The type used as a compile-time boolean with true value.
    typedef integral_constant<bool, true> true_type;
    /// The type used as a compile-time boolean with false value.
    typedef integral_constant<bool, false> false_type;

    template<typename T, T val>
    inline integral_constant<T, val>::operator value_type() const
    {
        return (value);
    }
    
    // template <class T>
    // struct is_integral : public integral_constant<
    // {};

    template <typename>
    struct is_integral : public false_type
    {};
    
    template <>
    struct is_integral<bool> : public true_type
    {};
    
    // char
    template <>
    struct is_integral<char> : public true_type
    {};
    
    /*
    // char16_t
    template <>
    struct is_integral<char16_t> : public true_type
    {};
    
    // char32_t
    template <>
    struct is_integral<char32_t> : public true_type
    {};
    */
    // wchar_t
    template <>
    struct is_integral<wchar_t> : public true_type
    {};
    
    // signed char
    template <>
    struct is_integral<signed char> : public true_type
    {};
    
    // short int
    template <>
    struct is_integral<short int> : public true_type
    {};
    
    // int
    template <>
    struct is_integral<int> : public true_type
    {};
    
    // long int
    template <>
    struct is_integral<long int> : public true_type
    {};
    
    // long long int
    template <>
    struct is_integral<long long int> : public true_type
    {};
    
    // unsigned char
    template <>
    struct is_integral <unsigned char> : public true_type
    {};
    
    // unsigned short int
    template <>
    struct is_integral <unsigned short int> : public true_type
    {};
    
    // unsigned int
    template <>
    struct is_integral <unsigned int> : public true_type
    {};
    
    // unsigned long int
    template <>
    struct is_integral <unsigned long int> : public true_type
    {};
    
    // unsigned long long int
    template <>
    struct is_integral <unsigned long long int> : public true_type
    {};
}

#endif
