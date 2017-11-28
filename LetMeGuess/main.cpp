#include <memory>
#include <iostream>
#include <string>

bool ask(std::string q){
    std::cout << q << std::endl;
    std::string a;
    std::cin >> a;

    
    while (a != "y" && a!= "Y" && a!= "n" && a!= "N"){
       	std::cout << "Please enter a valid input! (y/n)";
	std::cin >> a;
    }

    if (a == "y" || a == "Y") return true;
    else if(a == "n" || a == "N") return false;

}

struct Node{
    virtual void proc(std::shared_ptr<Node> &) = 0;
};

struct Question:Node{
	void proc(std::shared_ptr<Node> & p){
	    auto a = ask(question);
	    if (a) yes -> proc(yes);
	    else no->proc(no);
	}

	std::string question;
	std::shared_ptr<Node> yes;
	std::shared_ptr<Node> no;
	Question(std::string q, std::shared_ptr<Node> y = nullptr, std::shared_ptr<Node> n = nullptr) : question(q), yes(y), no(n){};
};

struct Answer : Node
{
    void proc(std::shared_ptr<Node> & p) override {
	auto a = ask("are you thinking of a(n) " + question);
	if(a) std::cout << "I win!! :D :D :D :D " << std::endl;
	else{
	    std::cin.ignore();
	    std::cout << ":( :( :( What were you thinking of? ";
	    std::string newAnswer;
	    std::getline(std::cin, newAnswer);
	    std::cout << "What could I have asked to know what you were thinking of " << newAnswer << " and not " << question << "?" << std::endl;
	    std::string newQuestion;
	    std::getline(std::cin, newQuestion);
	    std::cout << "I'll get you next time!!" << std::endl;

	    auto aNode = std::make_shared<Answer>(newAnswer);
	    p = std::make_shared<Question>(newQuestion, aNode, p);	    
	}
    }
	std::string question;
	Answer(std::string q) : question(q){};    
};

int main(){
    std::shared_ptr<Node> tree = std::make_shared<Answer>("an elephant? ");
	while (ask("Do you want to play? ")){
	tree->proc(tree);
	}
}
