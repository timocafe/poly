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

namespace poly{
    
    template<class P>
    struct listing{
        std::array<method,P::order_value+1> s;

        listing(){
            s[0]=method("bruteforce");
            s[1]=method("estrin");
            for(auto i=1; i < P::order_value  ; ++i)
                s[i+1]=method("horner",i);
        }

        auto begin() -> decltype(this->s.begin()) {
            return s.begin();
        }

        auto end() -> decltype(this->s.end()) {
            return s.end();
        }
    };

    template<class ...P>
    struct combinatory{};

    template<class P>
    struct combinatory<P>{
        void generate() {
            std::vector<produce> v;
            for(auto i = l.begin(); i != l.end(); ++i){
                produce p((*i).tag());
                p.add((*i));
                v.push_back(p);
            }
            helper_printer(v);
        }
        listing<P> l;
    };

    template<class P1, class P2>
    struct combinatory<P1, P2>{
        void generate() {
            std::vector<produce> v;
            for(auto i = l1.begin(); i != l1.end(); ++i)
                for(auto j = l2.begin(); j != l2.end(); ++j){
                    produce p((*i).tag()+(*j).tag());
                    p.add((*i));
                    p.add((*j));
                    v.push_back(p);
                }
            helper_printer(v);
        }
        listing<P1> l1;
        listing<P2> l2;
    };

    template<class P1, class P2, class P3>
    struct combinatory<P1, P2, P3>{
        void generate() {
            std::vector<produce> v;
            for(auto i = l1.begin(); l1 != l1.end(); ++i)
                for(auto j = l2.begin(); j != l2.end(); ++j)
                    for(auto k = j; k != l2.end(); ++k){
                        produce p((*i).tag()+(*j).tag()+(*k).tag());
                        p.add((*i));
                        p.add((*j));
                        p.add((*k));
                        v.push_back(p);
                    }
            helper_printer(v);
        }
        listing<P1> l1;
        listing<P2> l2;
    };

    template<class P1, class P2, class P3, class P4>
    struct combinatory<P1, P2, P3, P4>{
        void generate() {
            std::vector<produce> v;
            for(auto i = l1.begin(); i != l1.end(); ++i)
                for(auto j = l2.begin() ; j != l2.end(); ++j)
                    for(auto k = j; k != l2.end(); ++k)
                        for(auto l = k; l != l2.end(); ++l){
                            produce p((*i).tag()+(*j).tag()
                                      +(*k).tag()+(*l).tag());
                            p.add((*i));
                            p.add((*j));
                            p.add((*k));
                            p.add((*l));
                            v.push_back(p);
                        }
            helper_printer(v);
        }
        listing<P1> l1;
        listing<P2> l2;
    };

    template<class P1, class P2, class P3, class P4, class P5>
    struct combinatory<P1, P2, P3, P4, P5>{
        void generate() {
            int counter (0);
            std::vector<produce> v;
            for(auto i = l1.begin(); i != l1.end(); ++i)
                for(auto j = i; j != l1.end(); ++j)
                    for(auto k = j; k != l1.end(); ++k)
                        for(auto l = k; l != l1.end(); ++l)
                            for(auto m = l; m != l1.end(); ++m){
                                    produce p((*i).tag()+(*j).tag()
                                              +(*k).tag()+(*l).tag()+(*m).tag());
                                    p.add((*i));
                                    p.add((*j));
                                    p.add((*k));
                                    p.add((*l));
                                    p.add((*m));
                                    v.push_back(p);
                                    counter++;
                            }
            helper_printer(v);
        }
        listing<P1> l1; // P2.P2.P2.P2.P2, same degree one listing
    };
}

#endif