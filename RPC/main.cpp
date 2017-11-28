#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <exception>
#include "rational.hpp"
#include "polish.hpp"


int main() {
    
    bool init = true;	
    std::string userInput = " ";
    RPC rpc;

    std::cout << "This is a Reverse Polish Calculator." << std::endl;
    std::cout << "Enter the Rational numbers first followed by another rational number." << std::endl;
    std::cout << "When you are satisfied with the number of variables you would like to " << std::endl;
    std::cout << "calculate on, simply start adding operators for you to calculate." << std::endl;
    std::cout << std::endl;
    std::cout << "Press C to clear everything or press E to exit." << std::endl;

    while(init){
    std::getline(std::cin, userInput);
	try{
	    std::string temp;
	    std::stringstream ss {userInput};
	    while(ss>>temp){
		if(temp == "+"){
		    rpc.addR();
		}
		if(temp == "-"){
		    rpc.subR();
		}
		if(temp == "/"){
		    rpc.divR();
		}
		if(temp == "*"){
	            rpc.multR();
		}
		if(temp == "c" || temp == "C"){
		   std::cout << "Clearing the Calculator!" << std::endl;
		   rpc.clear();
		}
		if(temp == "e" || temp == "E"){
		   std::cout << "Exiting the Calculator!" << std::endl;
		   rpc.clear();
		   init = false;
		}
	    }
	rpc.push(temp);
	}
	catch (std::exception & e){
	    std::cerr << e.what() << std::endl;
	}
    }
    std::cout << "Thanks for using the Calculator!" << std::endl;
    return EXIT_SUCCESS;
}
