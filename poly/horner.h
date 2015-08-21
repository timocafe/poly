//
//  horner.h
//  poly
//
//  Created by Tim Ewart on 19/08/2015.
//
//

#ifndef poly_horner_h
#define poly_horner_h

    template<int n, int m, int q = n/poly_order::value, int r = n%poly_order::value> // quotient and remainder
    struct helper_horner{
        static inline double horner(double const& x){
#ifdef NDEBUG
            int debug_n = n;
            int debug_m = m;
            int debug_q = q;
            int debug_r = r;
#endif
            return coeff<n>::coefficient()+x*helper_horner<n+m,m>::horner(x);
        }
    };

    template<int n, int m>
    struct helper_horner<n,m,1,0>{ //quotien 1, remainder 0
        static inline double horner(double const&){
            return coeff<poly_order::value>::coefficient();
        }
    };

    template<int n, int m, int r>
    struct helper_horner<n,m,1,r>{ // looking for a coefficient larger than the max we stop q=1 r>0
        static inline double horner(double const&){
            return 0;
        }
    };

    template<int k,int m>
    struct helper_horner_kth{
        static inline double horner_kth(double const& x){
#ifdef NDEBUG
            int debug_k = k;
#endif
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

    template<int m>
    inline double horner_kth(double const& x){
        return helper_horner_kth<m,m>::horner_kth(x);
    }

#endif