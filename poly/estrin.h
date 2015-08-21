//
//  estrin.h
//  poly
//
//  Created by Tim Ewart on 19/08/2015.
//
//

#ifndef poly_estrin_h
#define poly_estrin_h

/* general test case, n is lower than the degree of the polynomial */
template<int n, bool b = (n<=poly_order::value)>
struct binomial_helper{
    inline const static double binomial(double const& x){
        return coeff<n>::coefficient() + x*coeff<n+1>::coefficient(); // a+b*x
    }
};

/* perticular case, n the degree of the polynomial */
template<>
struct binomial_helper<poly_order::value>{
    inline const static double binomial(double const& x){
        return coeff<poly_order::value>::coefficient(); // a
    }
};

/* requesting polynomial that does not exist */
template<int n>
struct binomial_helper<n,false>{
    inline const static double binomial(double const& x){
        return 0;
    }
};

template<int n>
inline double quadratic(double const& x){
    return binomial_helper<n>::binomial(x) + pow<2>(x)*binomial_helper<n+2>::binomial(x); // (a+b*x)+(c+d*x)*x^2
}

template<int n, bool = (n<=poly_order::value)>
struct helper_estrin{
    static inline double estrin(double const& x){
        return pow<2*n>(x)*quadratic<n>(x) + pow<2*n+1>(x)*helper_estrin<n+2>::estrin(x);
    }
};
 
template<int n>
struct helper_estrin<n,false>{
    static inline double estrin(double const& x){
        return 0;
    }
};

double estrin(double const& x){
    return binomial_helper<0>::binomial(x) + helper_estrin<4>::estrin(x);
}

#endif