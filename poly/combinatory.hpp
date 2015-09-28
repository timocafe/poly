//
//  combinatory.h
//  poly
//
//  Created by Tim Ewart on 19/08/2015.
//
//

#ifndef poly_combinatory_h
#define poly_combinatory_h

#include <array>
#include <ctime>

#include "poly/printer.h"
#include "poly/polynomial.h"
#include "poly/method/coefficients/coefficients.hpp"

#include <cassert>
namespace poly{
    

    struct listing{
        std::vector<method> s;

        listing(std::string name_coeff = std::string(), int order = 0):o(order){
            s.push_back(method("bruteforce",name_coeff,o));
            s.push_back(method("estrin",name_coeff,o));
            for(auto i=1; i < order ; ++i)
                s.push_back(method("horner_kth",name_coeff,o,i));
        }

        int size(){return s.size();}

        auto operator[](int i) -> decltype(this->s[i]){
            assert(i < s.size());
            return s[i];
        }
        int o;
    };

    enum decomposition {uno, duo, trio, quadri, pint};

    template<decomposition d>
    struct combinatory{};


    template<>
    struct combinatory<uno>{
        combinatory(std::string name_coeff  = std::string(), int order = 0):l(name_coeff,order){}

        void generate() {
            std::vector<produce> v;
            for(auto i = 0; i != l.size(); ++i){
                auto it = l[i];
                produce p(it.tag());
                p.add(it);
                v.push_back(p);
            }
            helper_printer(v);
        }
        listing l;
    };

    template<>
    struct combinatory<duo>{
        combinatory(std::string name_coeff1  = std::string(), int order1 = 0,
                    std::string name_coeff2  = std::string(), int order2 = 0
                    ):l1(name_coeff1,order1),l2(name_coeff2,order2){}

        void generate() {
            std::vector<produce> v;
            for(auto i = 0; i != l1.size(); ++i)
                for(auto j = 0; j != l2.size(); ++j){
                    auto iti = l1[i];
                    auto itj = l2[j];

                    produce p(iti.tag()+itj.tag());
                    p.add(iti);
                    p.add(itj);
                    v.push_back(p);
                }
            helper_printer(v);
        }
        listing l1;
        listing l2;
    };

    template<>
    struct combinatory<trio>{
        combinatory(std::string name_coeff1  = std::string(), int order1 = 0,
                    std::string name_coeff2  = std::string(), int order2 = 0,
                    std::string name_coeff3  = std::string(), int order3 = 0
                    ):l1(name_coeff1,order1),l2(name_coeff2,order2),l3(name_coeff3,order3){}


        void generate() {
            std::vector<produce> v;
            int counter(0);
            for(auto i = 0; i != l1.size(); ++i)
                for(auto j = 0; j != l2.size(); ++j)
                    for(auto k = j; k != l3.size(); ++k){
                        counter++;
                        auto iti = l1[i];
                        auto itj = l2[j];
                        auto itk = l3[k];

                        produce p(iti.tag()+itj.tag()+itk.tag());
                        p.add(iti);
                        p.add(itj);
                        p.add(itk);
                        v.push_back(p);
                    }
            helper_printer(v);
        }
        listing l1;
        listing l2;
        listing l3;
    };

    template<>
    struct combinatory<quadri>{
        combinatory(std::string name_coeff1  = std::string(), int order1 = 0,
                    std::string name_coeff2  = std::string(), int order2 = 0,
                    std::string name_coeff3  = std::string(), int order3 = 0,
                    std::string name_coeff4  = std::string(), int order4 = 0
                    ):l1(name_coeff1,order1),l2(name_coeff2,order2),
                      l3(name_coeff3,order3),l4(name_coeff4,order4){}

        void generate() {
            std::vector<produce> v;
    int counter(0);
            for(auto i = 0; i != l1.size(); ++i)
                for(auto j = 0 ; j != l2.size(); ++j)
                    for(auto k = j; k != l3.size(); ++k)
                        for(auto l = k; l != l4.size(); ++l){
                            counter++;
                            auto iti = l1[i];
                            auto itj = l2[j];
                            auto itk = l3[k];
                            auto itl = l4[l];


                            produce p(iti.tag()+itj.tag()
                                      +itk.tag()+itl.tag());
                            p.add(iti);
                            p.add(itj);
                            p.add(itk);
                            p.add(itl);
                            v.push_back(p);
                        }
            helper_printer(v);
        }
        listing l1;
        listing l2;
        listing l3;
        listing l4;
    };

    template<>
    struct combinatory<pint>{
        combinatory(std::string name_coeff1  = std::string(), int order1 = 0,
                    std::string name_coeff2  = std::string(), int order2 = 0,
                    std::string name_coeff3  = std::string(), int order3 = 0,
                    std::string name_coeff4  = std::string(), int order4 = 0,
                    std::string name_coeff5  = std::string(), int order5 = 0
                    ):l1(name_coeff1,order1),l2(name_coeff2,order2),
                      l3(name_coeff3,order3),l4(name_coeff4,order4),
                      l5(name_coeff5,order5){}

        void generate() {
            int counter (0);
            std::vector<produce> v;
            for(auto i = 0; i != l1.size(); ++i)
                for(auto j = i; j != l2.size(); ++j)
                    for(auto k = j; k != l3.size(); ++k)
                        for(auto l = k; l != l4.size(); ++l)
                            for(auto m = l; m != l5.size(); ++m){
                                    auto iti = l1[i];
                                    auto itj = l2[j];
                                    auto itk = l3[k];
                                    auto itl = l4[l];
                                    auto itm = l5[m];

                                    produce p(iti.tag()+itj.tag()+
                                              itk.tag()+itl.tag()+
                                              itm.tag());
                                    p.add(iti);
                                    p.add(itj);
                                    p.add(itk);
                                    p.add(itl);
                                    p.add(itm);
                                    v.push_back(p);
                                    counter++;
                            }
            helper_printer(v);
        }
        listing l1;
        listing l2;
        listing l3;
        listing l4;
        listing l5;
    };

 }

#endif
