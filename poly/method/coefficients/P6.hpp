//
//  P6.h
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_P6_h
#define poly_P6_h

namespace poly{
    template<int n>
    struct coeffP6{
    };

    template<>
    struct coeffP6<0>{
        const static inline double coefficient() {return 1;}
    };

    template<>
    struct coeffP6<1>{
        const static inline double coefficient() {return 1.196842960540944e+00;}
    };

    template<>
    struct coeffP6<2>{
        const static inline double coefficient() {return 6.678244594777292e-01;}
    };

    template<>
    struct coeffP6<3>{
        const static inline double coefficient() {return 2.243525483119196e-01;}
    };

    template<>
    struct coeffP6<4>{
        const static inline double coefficient() {return 4.846362961615892e-02;}
    };

    template<>
    struct coeffP6<5>{
        const static inline double coefficient() {return 6.505325568828364e-03;}
    };

    template<>
    struct coeffP6<6>{
        const static inline double coefficient() {return 4.379922390875640e-04;}
    };
}

#endif
