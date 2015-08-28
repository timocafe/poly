//
//  main.cpp
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <set>

#include <poly/iacaMarks.h>

#include "poly/poly.h"

#include "poly/polynomial.h"

using namespace poly;

void combinatory_poly(int degree1, int degree2){

    std::set<std::pair<std::string,int> > s1;
    s1.insert(std::make_pair("bruteforce", 1));
    s1.insert(std::make_pair("estrin", 1));
    s1.insert(std::make_pair("horner", degree1-1));

    std::set<std::pair<std::string,int> > s2;
    s2.insert(std::make_pair("bruteforce", 1));
    s2.insert(std::make_pair("estrin", 1));
    s2.insert(std::make_pair("horner", degree2-1));

    std::vector<produce> s3;

    for(auto i1 = s1.begin(); i1 != s1.end(); ++i1){
        for(int j1=1; j1<= (*i1).second; ++j1)
            for(auto i2 = s2.begin(); i2 != s2.end(); ++i2)
                for(int j2=1; j2<= (*i2).second; ++j2){
                    produce p;
                    p.add((*i1).first,j1);
                    p.add((*i2).first,j2);
                    s3.push_back(p);
                }
    }

    for(auto i = s3.begin(); i != s3.end(); ++i)
        std::cout << (*i).generate() << std::endl;
}




int main(int argc, const char * argv[]) {
    combinatory_poly(6,4);
//    double a = atof(argv[1]);
//    double t(0);

    std::set<std::string> s = {"bruteforce","estrin","horner"};








    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1) <<  std::endl;
//    t = poly::bruteforce<4,2>(a);
//    std::cout << t << std::endl;
 //   std::cout << " Horner order 1 " << t << std::endl;

/*

    t = poly::horner_kth<1>(a);
    std::cout << " Horner order 1 " << t << std::endl;
    t = poly::horner_kth<2>(a);
    std::cout << " Horner order 2 " << t << std::endl;
    t = poly::horner_kth<3>(a);
    std::cout << " Horner order 3 " << t << std::endl;
    t = poly::horner_kth<4>(a);
    std::cout << " Horner order 4 " << t << std::endl;
    t = poly::horner_kth<5>(a);
    std::cout << " Horner order 5 " << t << std::endl;
    t = poly::horner_kth<6>(a);
    std::cout << " Horner order 6 " << t << std::endl;
    t = poly::horner_kth<7>(a);
    std::cout << " Horner order 7 " << t << std::endl;
    t = poly::horner_kth<8>(a);
    std::cout << " Horner order 8 " << t << std::endl;
    t = poly::horner_kth<9>(a);
    std::cout << " Horner order 9 " << t << std::endl;
    t = poly::horner_kth<10>(a);
    std::cout << " Horner order 10 " << t << std::endl;
    t = poly::estrin<10>(a);
    std::cout << " Estrin " << t << std::endl;
    t = poly::factorization(a);
    std::cout << " factorization " << t << std::endl;
    t = poly::bruteforce<10>(a);
    std::cout << " bruteforce " << t << std::endl;
    std::cout << " bruteforce " << t << std::endl;
*/
 /*
#ifdef POLY_Horner1
    IACA_START
    t = poly::horner_kth<1>(a);
    IACA_END
    std::cout << " Horner order 1 " << t << std::endl;
#endif
    
#ifdef POLY_Horner2
    IACA_START
    t = poly::horner_kth<2>(a);
    IACA_END
    std::cout << " Horner order 2 " << t << std::endl;
#endif

#ifdef POLY_Horner3
    IACA_START
    t = poly::horner_kth<3>(a);
    IACA_END
    std::cout << " Horner order 3 " << t << std::endl;
#endif

#ifdef POLY_Horner4
    IACA_START
    t = poly::horner_kth<4>(a);
    IACA_END
    std::cout << " Horner order 4 " << t << std::endl;
#endif
    
#ifdef POLY_Horner5
    IACA_START
    t = poly::horner_kth<5>(a);
    IACA_END
    std::cout << " Horner order 5 " << t << std::endl;
#endif
   
#ifdef POLY_Horner6
    IACA_START
    t = poly::horner_kth<6>(a);
    IACA_END
    std::cout << " Horner order 6 " << t << std::endl;
#endif
    
#ifdef POLY_Horner7
    IACA_START
    t = poly::horner_kth<7>(a);
    IACA_END
    std::cout << " Horner order 7 " << t << std::endl;
#endif
    
#ifdef POLY_Horner8
    IACA_START
    t = poly::horner_kth<8>(a);
    IACA_END
    std::cout << " Horner order 8 " << t << std::endl;
#endif
    
#ifdef POLY_Horner9
    IACA_START
    t = poly::horner_kth<9>(a);
    IACA_END
    std::cout << " Horner order 9 " << t << std::endl;
#endif
    
#ifdef POLY_Horner10
    IACA_START
    t = poly::horner_kth<10>(a);
    IACA_END
    std::cout << " Horner order 10 " << t << std::endl;
#endif
    
#ifdef POLY_Estrin
    IACA_START
    t = poly::estrin<10>(a);
    IACA_END
    std::cout << " Estrin " << t << std::endl;
#endif

#ifdef POLY_Factorization
    IACA_START
    t = poly::factorization(a);
    IACA_END
    std::cout << " factorization " << t << std::endl;
#endif
    
#ifdef POLY_Bruteforce
    IACA_START
    t = poly::bruteforce(a);
    IACA_END
    std::cout << " bruteforce " << t << std::endl;
#endif
*/
    return 0;
}

