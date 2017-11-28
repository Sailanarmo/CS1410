#include "polish.hpp"
#include <string>
#include <sstream>

void RPC::print(){
    std::cout << stack << std::endl;
}

void RPC::push(std::string input){
    Rational rational;
    std::stringstream ss{input};
    while(ss>>rational){
	stack.emplace_back(rational);
    }
    print();
}

Rational RPC::pop(){
    auto temp = stack.back();
    stack.pop_back();
    return temp;
}

void RPC::clear(){
    stack.clear();
}


void RPC::addR(){
    op([](Rational a, Rational b){return a + b;});
}

void RPC::subR(){
    op([](Rational a, Rational b){return a - b;});
}

void RPC::divR(){
    op([](Rational a, Rational b){return a / b;});
}

void RPC::multR(){
    op([](Rational a, Rational b){return a * b;});
}
