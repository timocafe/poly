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

    /** the basic quadratic, obtained from complex conjugate roots, brute force compute */
    template<int n>
    struct bruteforce_poly{
        inline static const double quadratic(double const& x){
            return coeff_factorization<n,0>::coefficient()
                    + x*coeff_factorization<n,1>::coefficient()
                    + x*x*coeff_factorization<n,2>::coefficient(); // a+b*x+c*x^2
        }
    };

    /** the basic quadratic, obtained from complex conjugate roots, evalute using,
     On simultaenous evaluation of several polynomials of low degree (2 to 5) V. Ya. Pan
     USSR Computational Math. and Math. Physic 2 (1963), 137-146 */
    template<int n>
    struct pan_poly{
        inline static const double quadratic(double const& x){
            return x*(x+coeff_factorization<n,1>::coefficient())+coeff_factorization<n,2>::coefficient();
        }
    };

    /** factorization: recursive multiplication of quadratic
                    (P0)*(P1)*(P2)*(P3)*(P4)
                      \   /     \   /    /
                      (...)     (...)   /
                         \        /    /
                         (........)   /
                             \       /
                            (.Result.)
     */
    template<int n, int n0, class Q = pan_poly<n0> > // specify how calculate the quadratic
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

    template<int n0, class Q>
    struct factorization_helper<1,n0,Q>{
        inline static const double factorization(double const& x){
            return Q::quadratic(x);
        }
    };

    inline const double factorization(double const& x){
        return factorization_helper<5,0>::factorization(x);
    }

}
#endif
