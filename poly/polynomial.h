#pragma once

#include <vector>
#include <string>


namespace poly {

    class method{
    public:
        method(std::string const& m = std::string(), int i=0):n(m),it(i){}
        ~method(){};
        std::string  generate() const ;
        std::string const name() const;
        int const iteration() const;
        std::string const tag() const; //every decompostion is unique the tag also
    protected:
        std::string n;
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

