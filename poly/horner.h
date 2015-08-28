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

template<int n, int m, bool b = (n<=poly_order::value)>
    struct helper_horner{
        static inline double horner(double const& x){
            return coeff<n>::coefficient()+x*helper_horner<n+m,m>::horner(x);
        }
    };

    template<>
    struct helper_horner<poly_order::value,poly_order::value,true>{ // n is the max degree
        static inline double horner(double const&){
            return coeff<poly_order::value>::coefficient();
        }
    };

    template<int n, int m>
    struct helper_horner<n,m,false>{ // looking for a coefficient larger than the max degree
        static inline double horner(double const&){
            return 0;
        }
    };

/**
    Generalization of Horner's Rule for polynomial evaluation - W.S. Dorn, year 1962, page 240-245
    Horner k-order scheme - paper equation (3.4)
 */
    template<int k,int m>
    struct helper_horner_kth{
        static inline double horner_kth(double const& x){
            return pow<k-1>(x)*helper_horner<k-1,m>::horner(pow<m>(x))
                              +helper_horner_kth<k-1,m>::horner_kth(x);
        }
    };

    template<int m>
    struct helper_horner_kth<0,m>{
        static inline double horner_kth(double const& x){
            return 0;
        }
    };

    template<int m, int o=0>
    inline double horner_kth(double const& x){
        return helper_horner_kth<m,m>::horner_kth(x);
    }
}
#endif