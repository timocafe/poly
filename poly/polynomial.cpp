
#include <string>
#include "poly/polynomial.h"

namespace poly {

    std::string method::generate() const{
        if(name()=="horner")
            return name()+"<C,"+std::to_string(iteration())+">(x)";
        else
            return name()+"<C>(x)";
    }

    std::string const method::name() const{
        return n;
    }

    int const method::iteration() const{
        return it;
    }

    std::string const method::tag() const{
        std::string tag = std::string();
        if(name()=="horner")
            tag += name().front()+std::to_string(iteration());
        else
            tag += name().front(); // number useless for Estrin and BruteForce
        return tag;
    }

    std::string const produce::generate() const{
        std::string evaluation;
        for(auto it = v.begin(); it != v.end(); ++it)
            evaluation += it->generate()+"*";
        evaluation.pop_back(); // renove the last "*"
        evaluation += ";";
        return evaluation;
    }

    void produce::add(method const& p){
        v.push_back(p);
    }

    std::string const produce::tag() const{
        return t;
    }

}

