
#include <string>
#include "poly/polynomial.h"

namespace poly {

    std::string method::generate() const{
        if(name()=="Horner")
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
}

