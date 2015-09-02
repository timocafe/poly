//
//  P10
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#ifndef poly_P10_hpp
#define poly_P10_hpp

namespace poly{

    template<int n>
    struct coeffP10{
    };

    template<>
    struct coeffP10<0>{
        const static inline double coefficient() {return 1.0000000000000002114940639705245276038539149099858;}
    };

    template<>
    struct coeffP10<1>{
        const static inline double coefficient() {return 9.9999999999992204062922755139901673043089743845207e-1;}
    };

    template<>
    struct coeffP10<2>{
        const static inline double coefficient() {return 5.0000000000470407075910575853333558195136495835175e-1;}
    };

    template<>
    struct coeffP10<3>{
        const static inline double coefficient() {return 1.6666666655683517447526098517565535790685389986567e-1;}
    };

    template<>
    struct coeffP10<4>{
        const static inline double coefficient() {return 4.1666667972995034755573836934823984390148899855282e-2 ;}
    };

    template<>
    struct coeffP10<5>{
        const static inline double coefficient() {return 8.3333243238266834234997694128023285974769437237618e-3;}
    };

    template<>
    struct coeffP10<6>{
        const static inline double coefficient() {return  1.3889273989128108635846229092909917615429232247147e-3;}
    };

    template<>
    struct coeffP10<7>{
        const static inline double coefficient() {return 1.9830766718527367242381398724699378201454167561602e-4;}
    };

    template<>
    struct coeffP10<8>{
        const static inline double coefficient() {return  2.4984065458054751527321973285958377956147788917789e-5;}
    };

    template<>
    struct coeffP10<9>{
        const static inline double coefficient() {return 2.5615650803565837424935479251593631699833183180355e-6 ;}
    };

    template<>
    struct coeffP10<10>{
        const static inline double coefficient() {return 3.8874526912789884677625679351432816392776740411369e-7;}
    };

}

#endif
