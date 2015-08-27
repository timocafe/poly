#pragma once

#include <vector>

namespace poly {

    class method{
    public:
        method(std::string const& name):n(name){}
        virtual ~method(){};
        virtual std::string const generate(int d, int o) const = 0;
    protected:
        std::string n;
    };

    class bf : public method{
    public:
        bf():method("bruteforce"){}
        std::string const generate(int d, int o) const;
    };

    class polynomial{
    public:
        polynomial(int d=0, int o=0):degree(d),offset(o){};
        std::string const generate() const{
            return method1.generate(degree,offset);
        }
    private:
        int degree;
        int offset;
        bf method1;
    };

    class produce{
        std::string const generate() const{
            std::string evaluation;
            for(auto it = v.begin(); it != v.end(); ++it)
                evaluation += it->generate()+"*";
            return evaluation;
        }

    private:
        std::vector<polynomial> v;
    };

}

