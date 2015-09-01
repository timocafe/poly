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
#include "poly/polynomial.h"

#include "poly/poly.h"

//#include "poly/method/coefficients.hpp"


using namespace poly;

struct CoeffP10{
    static const int order_value = 10;
};

struct CoeffP8{
    static const int order_value = 8;
};

struct CoeffP2{
    static const int order_value = 2;
};


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



    double x = atof(argv[0]);

 //   IACA_START
    double y = bruteforce<10>(x);
  //  IACA_END

    std::cout << "y: " << y << std::endl;

    combinatory<CoeffP10> c;
    c.generate();

    return 0;
}

