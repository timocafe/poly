//
//  P8.h
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_P8_h
#define poly_P8_h

namespace poly{
    template<int n>
    struct coeffP8{
    };

    template<>
    struct coeffP8<0>{
        const static inline double coefficient() {return 1;}
    };

    template<>
    struct coeffP8<1>{
        const static inline double coefficient() {return 1.163731816647776e+00;}
    };

    template<>
    struct coeffP8<2>{
        const static inline double coefficient() {return  6.685406164211041e-01;}
    };

    template<>
    struct coeffP8<3>{
        const static inline double coefficient() {return 2.505267415059241e-01;}
    };

    template<>
    struct coeffP8<4>{
        const static inline double coefficient() {return 6.797843553794408e-02;}
    };

    template<>
    struct coeffP8<5>{
        const static inline double coefficient() {return 1.395214211513854e-02;}
    };

    template<>
    struct coeffP8<6>{
        const static inline double coefficient() {return 2.177858431827554e-03;}
    };

    template<>
    struct coeffP8<7>{
        const static inline double coefficient() {return 2.479549127807474e-04;}
    };

    template<>
    struct coeffP8<8>{
        const static inline double coefficient() {return 1.767079532120407e-05;}
    };
}

#endif
