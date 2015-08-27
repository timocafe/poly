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

    template<int n, int n0, int o>
    struct bruteforce_helper{
        inline static const double bruteforce(double const& x){
            return bruteforce_helper<n/2,n0,o>::bruteforce(x)
                    + bruteforce_helper<n-n/2,n0+n/2,o>::bruteforce(x);
        }
    };

    template<int n0, int o>
    struct bruteforce_helper<0,n0,o>{
        inline static const double bruteforce(double const& x){
            return 0;
        }
    };

    template<int n0, int o>
    struct bruteforce_helper<1,n0,o>{
        inline static const double bruteforce(double const& x){
            return pow<n0>(x)*coeff<n0+o>::coefficient(); // offset act here
        }
    };

    template<int n, int o = 0> // o = offset
    inline const double bruteforce(double const& x){
        return bruteforce_helper<n,0,o>::bruteforce(x);
    }


}
#endif