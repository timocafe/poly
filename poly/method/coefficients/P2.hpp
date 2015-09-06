//
//  P2.h
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_P2_h
#define poly_P2_h

namespace poly{

    template<int n>
    struct coeffP2_1;

    template<int n>
    struct coeffP2_2;

    template<int n>
    struct coeffP2_3;

    template<int n>
    struct coeffP2_4;

    template<int n>
    struct coeffP2_5;

    /* P1 */
    template<>
    struct coeffP2_1<0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeffP2_1<1>{
        const static inline double coefficient() {return 5.863999468698624e-01;}
    };

    template<>
    struct coeffP2_1<2>{
        const static inline double coefficient() {return 9.111669706698734e-02;}
    };

    /* P2 */
    template<>
    struct coeffP2_2<0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeffP2_2<1>{
        const static inline double coefficient() {return 4.250022501401942e-01;}
    };

    template<>
    struct coeffP2_2<2>{
        const static inline double coefficient() {return 7.935993577895180e-02;}
    };

    /* P3 */
    template<>
    struct coeffP2_3<0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeffP2_3<1>{
        const static inline double coefficient() {return 1.854407635308873e-01;}
    };

    template<>
    struct coeffP2_3<2>{
        const static inline double coefficient() {return 6.057133407964636e-02;}
    };

    /* P4 */
    template<>
    struct coeffP2_4<0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeffP2_4<1>{
        const static inline double coefficient() {return -3.311114389316798e-02  ;}
    };

    template<>
    struct coeffP2_4<2>{
        const static inline double coefficient() {return 4.034499642737116e-02;}
    };

    /* P5 */
    template<>
    struct coeffP2_5<0>{
        const static inline double coefficient() {return 1.000000000000000e00;}
    };

    template<>
    struct coeffP2_5<1>{
        const static inline double coefficient() {return -1.637318166478535e-01;}
    };

    template<>
    struct coeffP2_5<2>{
        const static inline double coefficient() {return 2.199930801424831e-02;}
    };
}
#endif
