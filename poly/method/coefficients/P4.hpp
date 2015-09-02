//
//  P4.h
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_P4P2P2P2_h
#define poly_P4P2P2P2_h

namespace poly{
    /* from P4P2P2P2 */
    template<int n>
    struct coeffP4_1{
    };

    template<>
    struct coeffP4_1<0>{
        const static inline double coefficient() {return 1;}
    };

    template<>
    struct coeffP4_1<1>{
        const static inline double coefficient() {return 1.011402197010057e+00;}
    };

    template<>
    struct coeffP4_1<2>{
        const static inline double coefficient() {return   4.196979297477210e-01;}
    };

    template<>
    struct coeffP4_1<3>{
        const static inline double coefficient() {return 8.526146340318508e-02;}
    };

    template<>
    struct coeffP4_1<4>{
        const static inline double coefficient() {return  7.231015227626321e-03;}
    };

    /* from P4P4P2 */
    template<int n>
    struct coeffP4_2{
    };

    template<>
    struct coeffP4_2<0>{
        const static inline double coefficient() {return 1;}
    };

    template<>
    struct coeffP4_2<1>{
        const static inline double coefficient() {return 1.523296196377193e-01;}
    };

    template<>
    struct coeffP4_2<2>{
        const static inline double coefficient() {return 9.477617470208738e-02;}
    };

    template<>
    struct coeffP4_2<3>{
        const static inline double coefficient() {return 5.476020783630308e-03;}
    };

    template<>
    struct coeffP4_2<4>{
        const static inline double coefficient() {return 2.443750257044438e-03;}
    };

    /* from P6P4 */
    template<int n>
    struct coeffP4_3{
    };

    template<>
    struct coeffP4_3<0>{
        const static inline double coefficient() {return 1;}
    };

    template<>
    struct coeffP4_3<1>{
        const static inline double coefficient() {return -1.968429605410215e-01;}
    };

    template<>
    struct coeffP4_3<2>{
        const static inline double coefficient() {return  6.776565218253636e-02;}
    };

    template<>
    struct coeffP4_3<3>{
        const static inline double coefficient() {return -7.334181810914540e-03;}
    };

    template<>
    struct coeffP4_3<4>{
        const static inline double coefficient() {return  8.875620032394859e-04;}
    };
}

#endif
