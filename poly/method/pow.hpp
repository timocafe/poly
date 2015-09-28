//
//  pow.h
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_pow_h
#define poly_pow_h

namespace poly{

    template<int M, int K = M%2>
    struct pow_helper{
        static inline double pow(const double a){
             return pow_helper<M/2>::pow(a)*pow_helper<M/2>::pow(a);
        }
    };

    template<int M>
    struct pow_helper<M,1>{
        static inline double pow(const double a){
             return a*pow_helper<M/2>::pow(a)*pow_helper<M/2>::pow(a);
        }
    };

    template<>
    struct pow_helper<1,1>{
        static inline double pow(const double a){
             return a;
        }
    };

    template<>
    struct pow_helper<0,0>{
        static inline double pow(const double a){
             return 1;
        }
    };

    template<int M>
    inline double pow(const double a){
        return pow_helper<M>::pow(a);
    }

}
#endif
