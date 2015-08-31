//
//  main.cpp
//  poly
//
//  Created by Ewart Timothée on 18/08/15.
//  Copyright (c) 2015 Ewart Timothée. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <array>

#include <poly/iacaMarks.h>

#include "poly/poly.h"

#include "poly/polynomial.h"

using namespace poly;

void combinatory_uni_poly(){

    std::array<method,3> s = {method("bruteforce"),method("estrin"),method("horner1")};

    std::vector<produce> s3;

    for(auto i = s.begin(); i != s.end(); ++i){
        produce p;
        p.add((*i));
        s3.push_back(p);
    }

    for(auto i = s3.begin(); i != s3.end(); ++i)
        std::cout << (*i).generate() << std::endl;
}

void combinatory_duo_poly(){

    std::array<method,3> s = {method("bruteforce"),method("estrin"),method("horner")};

    std::vector<produce> s3;

    for(auto i = s.begin(); i != s.end(); ++i)
        for(auto j = i; j != s.end(); ++j){
            produce p;
            p.add((*i));
            p.add((*j));
            s3.push_back(p);
        }


    for(auto i = s3.begin(); i != s3.end(); ++i)
        std::cout << (*i).generate() << std::endl;
}


void combinatory_duo_poly_full(){

    std::array<method,3> s = {method("bruteforce"),method("estrin"),method("horner")};

    std::vector<produce> s3;

    for(auto i = s.begin(); i != s.end(); ++i)
        for(auto j = s.begin(); j != s.end(); ++j){
            produce p;
            p.add((*i));
            p.add((*j));
            s3.push_back(p);
        }


    for(auto i = s3.begin(); i != s3.end(); ++i)
        std::cout << (*i).generate() << std::endl;
}


void combinatory_tri_poly(){

    std::array<method,3> s = {method("bruteforce"),method("estrin"),method("horner")};

    std::vector<produce> s3;

    for(auto i = s.begin(); i != s.end(); ++i)
        for(auto j = i; j != s.end(); ++j)
            for(auto k = j; k != s.end(); ++k){
                produce p;
                p.add((*i));
                p.add((*j));
                p.add((*k));
                s3.push_back(p);
            }

    for(auto i = s3.begin(); i != s3.end(); ++i)
        std::cout << (*i).generate() << std::endl;
}


void combinatory_tri_full_poly(){

    std::array<method,3> s = {method("bruteforce"),method("estrin"),method("horner")};

    std::vector<produce> s3;

    for(auto i = s.begin(); i != s.end(); ++i)
        for(auto j = s.begin(); j != s.end(); ++j)
            for(auto k = j; k != s.end(); ++k){
                produce p;
                p.add((*i));
                p.add((*j));
                p.add((*k));
                s3.push_back(p);
            }

    for(auto i = s3.begin(); i != s3.end(); ++i)
        std::cout << (*i).generate() << std::endl;
}



void combinatory_quadri_poly(){

    std::array<method,3> s = {method("bruteforce"),method("estrin"),method("horner")};

    std::vector<produce> s3;

    for(auto i = s.begin(); i != s.end(); ++i)
        for(auto j = s.begin() ; j != s.end(); ++j)
            for(auto k = j; k != s.end(); ++k)
                for(auto l = k; l != s.end(); ++l){
                    produce p;
                    p.add((*i));
                    p.add((*j));
                    p.add((*k));
                    p.add((*l));
                    s3.push_back(p);
            }

    for(auto i = s3.begin(); i != s3.end(); ++i)
        std::cout << (*i).generate() << std::endl;
}

void combinatory_sext_poly(){

    std::array<method,3> s = {method("bruteforce"),method("estrin"),method("horner")};

    std::vector<produce> s3;

    for(auto i = s.begin(); i != s.end(); ++i)
        for(auto j = i; j != s.end(); ++j)
            for(auto k = j; k != s.end(); ++k)
                for(auto l = k; l != s.end(); ++l)
                    for(auto m = l; m != s.end(); ++m)
                        for(auto n = m; n != s.end(); ++n){
                            produce p;
                            p.add((*i));
                            p.add((*j));
                            p.add((*k));
                            p.add((*l));
                            p.add((*m));
                            p.add((*n));
                            s3.push_back(p);
                        }

    for(auto i = s3.begin(); i != s3.end(); ++i)
        std::cout << (*i).generate() << std::endl;
}

struct combinatory{
    std::array<method,3> s = {method("bruteforce"),method("estrin"),method("horner")};
};

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

    {
    combinatory<CoeffP10> c;
    c.generate();
    }

    {
        combinatory<CoeffP8,CoeffP2> c;
        c.generate();
    }

    /*
    std::string s1 = "A", s2 = "B";
    std::string sum = adder(s1, s2);
    std::cout << sum << std::endl;
*/
    /*
    std::cout << " UNI ---------------------- " << std::endl;
    combinatory_uni_poly();
    std::cout << " DUO ---------------------- " << std::endl;
    combinatory_duo_poly();
    std::cout << " DUO FULL ----------------- " << std::endl;
    combinatory_duo_poly_full();
    std::cout << " TRI ---------------------- " << std::endl;
    combinatory_tri_poly();
    std::cout << " TRI FULL ----------------- " << std::endl;
    combinatory_tri_full_poly();
    std::cout << " QUADRI ------------------- " << std::endl;
    combinatory_quadri_poly();
    std::cout << " SEXT --------------------- " << std::endl;
    combinatory_sext_poly();

*/

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

