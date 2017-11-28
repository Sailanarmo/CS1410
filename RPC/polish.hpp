#ifndef REVERSE_POLISH_CALC
#define REVERSE_POLISH_CALC

#include <vector>
#include <stdexcept>
//#include <exception> <- why no work?!
#include "rational.hpp"


class RPC{

public:
    void print();
    template<typename F>
    void op(F);
    void push(std::string);
    void clear();

    void addR();
    void subR();
    void divR();
    void multR();

private:
    std::vector<Rational> stack;
    Rational pop();

};

template<typename T>
std::ostream& operator<< (std::ostream& o, std::vector<T> const & v){
    for(auto & e : v){
	o << e << " | ";
    }
    return o;
}

template<typename F>
void RPC::op(F f){
    if(stack.size() < 2){
        throw std::domain_error("Stack does not have 2 variables, please insert another variable.");
    }
    auto second = pop();
    auto first = pop();
    this->stack.push_back(f(first,second));
}


#endif
