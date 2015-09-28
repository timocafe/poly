//
//  horner.h
//  poly
//
//  Created by Tim Ewart on 19/08/2015.
//
//

#ifndef poly_horner_h
#define poly_horner_h

namespace poly{

    template<template <int> class C, int n, int m, bool b1 = (n<=poly_order<C>::value),
                                                   bool b2 = (n == poly_order<C>::value)> // idem than estrin pb
    struct helper_horner{
        static inline double horner(double const x){
            return C<n>::coefficient()+x*helper_horner<C,n+m,m>::horner(x);
        }
    };

    template<template <int> class C,int n, int m>
    struct helper_horner<C,n,m,true,true>{ // n is the max degree
        static inline double horner(double const){
            return C<poly_order<C>::value>::coefficient();
        }
    };

    template<template <int> class C,int n, int m>
    struct helper_horner<C,n,m,false,false>{ // looking for a coefficient larger than the max degree
        static inline double horner(double const){
            return 0;
        }
    };

/**
    Generalization of Horner's Rule for polynomial evaluation - W.S. Dorn, year 1962, page 240-245
    Horner k-order scheme - paper equation (3.4)
 */
    template<template <int> class C,int k,int m>
    struct helper_horner_kth{
        static inline double horner_kth(double const x){
            return pow<k-1>(x)*helper_horner<C,k-1,m>::horner(pow<m>(x))
                              +helper_horner_kth<C,k-1,m>::horner_kth(x);
        }
    };

    template<template <int> class C,int m>
    struct helper_horner_kth<C,0,m>{
        static inline double horner_kth(double const x){
            return 0;
        }
    };

    template<template <int> class C, int m>
    inline double horner_kth(double const x){
        return helper_horner_kth<C,m,m>::horner_kth(x);
    }
}
#endif