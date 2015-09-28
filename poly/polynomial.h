#pragma once

#include <vector>
#include <string>


namespace poly {

    class method{
    public:
        method(std::string const& m = std::string(),
               std::string o = std::string(),
               int d = 0, int i=0):n(m),c(o),order(d),it(i){}
        ~method(){};
        std::string  generate() const ;
        std::string const name() const;
        std::string const coefficient() const;
        int  iteration() const;
        int  degree() const;
        std::string const tag() const; //every decompostion is unique the tag also
    protected:
        std::string n; // name of the method
        std::string c; // name of the corresponding coefficient
        int order; // order of the polynomial
        int it; // 0 for BF, ES, Degree-1 for horner
    };

    class produce{
    public:
        produce(std::string const & tag = std::string()):t(tag){}
        void add(method const& p);
        std::string const generate() const;
        std::string const tag() const;
    private:
        std::vector<method> v;
        std::string t; // tag
    };
}

