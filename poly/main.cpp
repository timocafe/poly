//
//  main.cpp
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#include <iostream>
#include <iomanip>

#include <poly/iacaMarks.h>

#include "poly/combinatory.hpp"

#include "poly/poly.h"

//#include "poly/method/coefficients.hpp"


using namespace poly;


int main(int argc, const char * argv[]) {

//    {
//         combinatory<CoeffP2,CoeffP2,CoeffP2,CoeffP2,CoeffP2> c;
//         c.generate();
//    }
//
//    {
//        combinatory<CoeffP8,CoeffP2> c;
//        c.generate();
//    }

    {
        combinatory<decomposition::uno> c("coeffP10",10);
        c.generate();
    }

    {
        combinatory<decomposition::duo> c("coeffP8",8,"coeffP2_5",2);
        c.generate();
    }

    {
        combinatory<decomposition::duo> c("coeffP6",6,"coeffP4_3",4);
        c.generate();
    }

    {
        combinatory<decomposition::trio> c("coeffP6",6,"coeffP2_4",2,"coeffP2_5",2);
        c.generate();
    }

    {
        combinatory<decomposition::trio> c("coeffP2_5",2,"coeffP4_1",4,"coeffP4_2",4); // P4P4P2 = P2P4P4
        c.generate();
    }

    {
        combinatory<decomposition::quadri> c("coeffP4_1",4,"coeffP2_3",2,"coeffP2_4",2,"coeffP2_5",2);
        c.generate();
    }

    {
        combinatory<decomposition::pint> c("coeffP2_1",2,"coeffP2_2",2,"coeffP2_3",2,"coeffP2_4",2,"coeffP2_5",2);
        c.generate();
    }

/*
    double x = atof(argv[1]);

 //   IACA_START
    double y = bruteforce<coeff>(x);
    std::cout << "y: " << y << std::endl;

    y = estrin<coeff>(x);
    std::cout << "y: " << y << std::endl;

    y = horner_kth<coeff,1>(x);
    std::cout << "y: " << y << std::endl;

    y = horner_kth<coeff,2>(x);
    std::cout << "y: " << y << std::endl;
    y = horner_kth<coeff,3>(x);
    std::cout << "y: " << y << std::endl;
    y = horner_kth<coeff,4>(x);
    std::cout << "y: " << y << std::endl;
    y = horner_kth<coeff,5>(x);
    std::cout << "y: " << y << std::endl;
    y = horner_kth<coeff,6>(x);
    std::cout << "y: " << y << std::endl;
    y = horner_kth<coeff,7>(x);
    std::cout << "y: " << y << std::endl;
    y = horner_kth<coeff,8>(x);
    std::cout << "y: " << y << std::endl;
    y = horner_kth<coeff,9>(x);
    std::cout << "y: " << y << std::endl;
    y = horner_kth<coeff,10>(x);
    std::cout << "y: " << y << std::endl;

*/

//    combinatory<CoeffP10> c;
//    c.generate();

    return 0;
}

