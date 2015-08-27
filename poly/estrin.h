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
    template<int i, bool b = (i<=poly_order::value)>
    struct binomial_helper{
        inline const static double binomial(double const& x){
            return coeff<i>::coefficient() + x*coeff<i+1>::coefficient(); // a+b*x
        }
    };

    /** perticular case, i the degree of the polynomial */
    template<>
    struct binomial_helper<poly_order::value>{
        inline const static double binomial(double const& x){
            return coeff<poly_order::value>::coefficient(); // a
        }
    };

    /** perticular case, coefficent i does not exist */
    template<int i>
    struct binomial_helper<i,false>{
        inline const static double binomial(double const& x){
            return 0;
        }
    };

    /** Generalization of Horner's Rule for polynomial evaluation - W.S. Dorn, IBM journal, year 1962, page 240-245
     Estrin scheme - paper equation (3.6)
     */
    template<int i, int n>
    struct helper_estrin{
        static inline double estrin(double const& x){
            return helper_estrin<i,n-1>::estrin(x) + pow<2*n>(x)*helper_estrin<i+(1<<n),n-1>::estrin(x);
        }
    };

    /** Generalization of Horner's Rule for polynomial evaluation - W.S. Dorn, IBM journal, year 1962, page 240-245
     Estrin scheme - final specialization - paper equation (3.5)
     */
    template<int i>
    struct helper_estrin<i,0>{
        static inline double estrin(double const& x){
            return binomial_helper<i>::binomial(x);
        }
    };

    double estrin(double const& x){
        return helper_estrin<0,10>::estrin(x);
    }
}

#endif