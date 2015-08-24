//
//  factorization.h
//  poly
//
//  Created by Tim Ewart on 19/08/2015.
//
//

#ifndef poly_factorization_h
#define poly_factorization_h

namespace poly{

    /** the basic quadratic, obtained from complex conjugate roots */
    template<int n>
    inline const double quadratic(double const& x){
        return coeff_factorization<n,0>::coefficient()
                + x*coeff_factorization<n,1>::coefficient()
                + x*x*coeff_factorization<n,2>::coefficient(); // a+b*x+c*x^2
    }

    /** factorization: recursive multiplication of quadratic
                    (P0)*(P1)*(P2)*(P3)*(P4)
                      \   /     \   /    /
                      (...)     (...)   /
                         \        /    /
                         (........)   /
                             \       /
                            (.Result.)
     */
    template<int n, int n0>
    struct factorization_helper{
        inline static const double factorization(double const& x){
            return factorization_helper<n/2,n0>::factorization(x)
                    * factorization_helper<n-n/2,n0+n/2>::factorization(x);
        }
    };

    template<int n0>
    struct factorization_helper<0,n0>{
        inline static const double factorization(double const& x){
            return 1;
        }
    };

    template<int n0>
    struct factorization_helper<1,n0>{
        inline static const double factorization(double const& x){
            return quadratic<n0>(x);
        }
    };

    inline const double factorization(double const& x){
        return 1 + factorization_helper<5,0>::factorization(x);
    }

}
#endif