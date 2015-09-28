//
//  estrin.h
//  poly
//
//  Created by Tim Ewart on 19/08/2015.
//
//

#ifndef poly_estrin_h
#define poly_estrin_h

namespace poly{

    /** general test case, i is lower than the degree of the polynomial */
    template<template <int> class C,int i, bool b1 = (i<=poly_order<C>::value), bool b2 = (i == poly_order<C>::value)>
    struct binomial_helper{
        inline const static double binomial(double const x){
            return C<i>::coefficient() + x*C<i+1>::coefficient(); // a+b*x
        }
    };

    /** perticular case, i the degree of the polynomial */
    template<template <int> class C, int i>
    struct binomial_helper<C,i,true,true>{ // do i = poly_order<C>::value does not work so I add b2
        inline const static double binomial(double const x){
            return C<poly_order<C>::value>::coefficient(); // a
        }
    };

    /** perticular case, coefficent i does not exist */
    template<template <int> class C, int i>
    struct binomial_helper<C,i,false,false>{
        inline const static double binomial(double const x){
            return 0;
        }
    };

    /** Generalization of Horner's Rule for polynomial evaluation - W.S. Dorn, IBM journal, year 1962, page 240-245
     Estrin scheme - paper equation (3.6)
     */
    template<template <int> class C, int i, int n>
    struct helper_estrin{
        static inline double estrin(double const x){
            return helper_estrin<C,i,n-1>::estrin(x) + pow<2*n>(x)*helper_estrin<C,i+(1<<n),n-1>::estrin(x);
        }
    };

    /** Generalization of Horner's Rule for polynomial evaluation - W.S. Dorn, IBM journal, year 1962, page 240-245
     Estrin scheme - final specialization - paper equation (3.5)
     */
    template<template <int> class C, int i>
    struct helper_estrin<C,i,0>{
        static inline double estrin(double const x){
            return binomial_helper<C,i>::binomial(x);
        }
    };

    template<template <int> class C>
    inline double estrin(double const x){
        return helper_estrin<C,0,poly_order<C>::value>::estrin(x);
    }

}

#endif