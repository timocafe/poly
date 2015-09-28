//
//  bruteforce.h
//  poly
//
//  Created by Tim Ewart on 19/08/2015.
//
//

#ifndef poly_bruteforce_h
#define poly_bruteforce_h

#include <string>

namespace poly{

    template< template <int> class C, int n, int n0>
    struct bruteforce_helper{
        inline static const double bruteforce(double const x){
            return bruteforce_helper<C,n/2,n0>::bruteforce(x)
                    + bruteforce_helper<C,n-n/2,n0+n/2>::bruteforce(x);
        }
    };

    template<template <int> class C, int n0>
    struct bruteforce_helper<C,0,n0>{
        inline static const double bruteforce(double const x){
            return 0;
        }
    };

    template<template <int k> class C, int n0>
    struct bruteforce_helper<C,1,n0>{
        inline static const double bruteforce(double const x){
            return pow<n0>(x)*C<n0>::coefficient(); // offset act here
        }
    };

    template< template <int> class C>
    inline const double bruteforce(double const x){
        return bruteforce_helper<C, poly_order<C>::value+1,0>::bruteforce(x);
    }


}
#endif