//
//  estrin.h
//  poly
//
//  Created by Tim Ewart on 19/08/2015.
//
//

#ifndef poly_estrin_h
#define poly_estrin_h

template<int n>
template<int n, int m, int q = n/poly_order::value, int r = n%poly_order::value>
struct
inline double binomial(double const& x){
    return coeff<n>::coefficient() + x*coeff<n+1>::coefficient(); // a+b*x
}

template<int n>
inline double quadratic(double const& x){
    return binomial<n>(x) + pow<2>(x)*binomial<n+2>(x); // (a+b*x)+(c+d*x)*x^2
}


template<int n>
struct helper_estrin{
    static inline double estrin(double const& x){
        return pow<2*n>(a)*... + pow<
    }
};




double estrin(double const& x){
    return binomial<0>(x) + helper_estrin
}



#endif