
#include <string>
#include "poly/polynomial.h"

namespace poly {

    std::string method::generate() const{
        if(name()=="horner_kth")
            return "poly::"+name()+"<poly::"+coefficient()+","+std::to_string(iteration())+">(x)";
        else
            return "poly::"+name()+"<poly::"+coefficient()+">(x)";
    }

    std::string method::cyme_generate() const{
        if(name()=="horner_kth")
            return "poly::"+name()+"<T,O,N,poly::"+coefficient()+","+std::to_string(iteration())+">(x)";
        else
            return "poly::"+name()+"<T,O,N,poly::"+coefficient()+">(x)";
    }


    std::string const method::name() const{
        return n;
    }

    std::string const method::coefficient() const{
        return c;
    }

    int method::iteration() const{
        return it;
    }

    int method::degree() const{
        return order;
    }

    std::string const method::tag() const{
        std::string tag = std::string();
        if(name()=="horner_kth"){
            tag += name().front();
            tag += "kth"+std::to_string(iteration());
            tag += "d"+std::to_string(degree());
        }else{
            tag += name().front(); // number useless for Estrin and BruteForce
            tag += "d"+std::to_string(degree());
        }
        return tag;
    }

    std::string const produce::generate() const{
        std::string evaluation;
        for(auto it = v.begin(); it != v.end(); ++it)
            evaluation += it->generate()+"*";
        evaluation.pop_back(); // renove the last "*"
        evaluation += "";
        return evaluation;
    }
    std::string const produce::cyme_generate() const{
        std::string evaluation;
        for(auto it = v.begin(); it != v.end(); ++it)
            evaluation += it->cyme_generate()+"*";
        evaluation.pop_back(); // renove the last "*"
        evaluation += "";
        return evaluation;
    }

    void produce::add(method const& p){
        v.push_back(p);
    }

    std::string const produce::tag() const{
        return t;
    }

}

