//
//  combinatory.h
//  poly
//
//  Created by Tim Ewart on 19/08/2015.
//
//

#ifndef poly_combinatory_h
#define poly_combinatory_h

#include "poly/polynomial.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace poly{

    template<class P>
    struct listing{
        listing(){
            s.push_back(method("bruteforce"));
            s.push_back(method("estrin"));
            for(auto i=1; i < P::order_value; ++i)
                s.push_back(method("Horner",i));
        }

        std::vector<method>::iterator begin(){
            return s.begin();
        }

        std::vector<method>::const_iterator end(){
            return s.end();
        }

        std::vector<method> s;
    };

    struct printer{
        std::ostream& operator()(std::ostream& ps, std::string const& produce ) const;
    };

    std::ostream& printer::operator()(std::ostream &ps, std::string const& produce ) const {
        ps << "include \"poly/poly.h \" \n";
        ps << "int main(int argc, char * argv []){ \n";
        ps << "    IACA_START \n";
        ps << "    " + produce + " \n";
        ps << "    IACA_END \n";
        ps << "    return 0; \n";
        ps << "} \n";
        return ps;
    }

    void helper_printer(std::vector<produce> const & v){ // screen and file
        printer p;
        std::ostringstream buf;
        std::cout << buf.str() << std::endl;
        for(auto i = v.begin(); i != v.end(); ++i){
            p(buf,(*i).generate());
            std::cout << buf.str() << std::endl; // screen
//            std::ofstream fout("test.out"); //file
//            fout  << buf.str() << '\n';
        }
    }




    template<class ...P>
    struct combinatory{};

    template<class P>
    struct combinatory<P>{
        void generate() {
            std::vector<produce> v;
            for(auto i = l.begin(); i != l.end(); ++i){
                produce p;
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
            for(auto i = l1.begin(); i != l1.end(); ++i){
                for(auto j = l2.begin(); j != l2.end(); ++j){
                    produce p;
                    p.add((*i));
                    p.add((*j));
                    v.push_back(p);
                }
            }
            helper_printer(v);
        }
        listing<P1> l1;
        listing<P2> l2;
    };


}

#endif