//
//  estrin.h
//  poly
//
//  Created by Tim Ewart on 19/08/2015.
//
//

#ifndef poly_estrin_h
#define poly_estrin_h

template<int n, int k = n%2>
struct helper_binomial{
    inline double binomial(double const& a){
        return coeff<n>::coefficient() + a*coeff<n+1>::coefficient();
    }
}

template<int k = n%2>
struct helper_binomial{
    inline double binomial(double const& a){
        return coeff<n>::coefficient() + a*coeff<n+1>::coefficient();
    }
}


#endif