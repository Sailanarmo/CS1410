#include <iostream>
#include <cstdlib>
#include "linkList.hpp"

template<typename T>
void print(T const & t){

    std::cout << t << ' ';

}

template<typename T>
LinkedList<T> buildList(LinkedList<T> list){
    
    LinkedList<T> newList;
    newList = list;
    return newList;

}


int main(){


    LinkedList<int> a;
    LinkedList<double> b;


    //inserting numbers into the linked list.
    a.insert(1);
    a.insert(12);
    a.insert(22);
    a.insert(5);
    a.insert(9);
    a.insert(14);
    a.insert(59);
    a.insert(14);
    a.insert(16);
    a.insert(14);
    a.insert(12);


    std::cout << "Example with Integers" << std::endl;
    std::cout << "Before Removing from List: " << std::endl;
    a.forEach(print<int>);
    std::cout << "Size: " << a.size() << std::endl;

    //starting to remove the numbers from the linked list.
    a.remove(5);
    a.remove(12);
    a.remove(12);
    a.remove(14);
    a.remove(14);
    std::cout << std::endl;
    std::cout << "After Removing from List: " << std::endl;
    a.forEach(print<int>);
    std::cout << "Size: " << a.size() << std::endl;
    std::cout << std::endl;

    b.insert(21.3);
    b.insert(1.3);
    b.insert(1.9);
    b.insert(2.3);
    b.insert(11.12);
    b.insert(29.3);
    b.insert(51.99);
    b.insert(12.3);
    b.insert(5.1);
    b.insert(21.3);
    b.insert(21.3);

    std::cout << "Example with Doubles" << std::endl;
    std::cout << "Before Removing from List: " << std::endl;
    b.forEach(print<double>);
    std::cout << "Size: " << b.size() << std::endl;

    b.remove(2.3);
    b.remove(29.3);
    b.remove(21.3);
    b.remove(21.3);
    std::cout << std::endl;
    std::cout << "After Removing from list: " << std::endl;
    b.forEach(print<double>);
    std::cout << "Size: " << b.size() << std::endl;
    std::cout << std::endl;

 
    LinkedList<int> list1 = buildList(a);
    std::cout << "Example of Shallow Copy: " << std::endl;
    list1.forEach(print<int>);
    std::cout << std::endl;
    std::cout << "Inserting a 99" << std::endl;
    a.insert(99);
    list1 = buildList(a);
    LinkedList<int> list2 = list1;
    std::cout << "Original List: ";
    list2.forEach(print<int>);
    
    list2 = std::move(list1);
   
    std::cout << std::endl;
    std::cout << "Still same Copy: "; 
    list2.forEach(print<int>);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Example of Deep Copy: " << std::endl;
   
    std::cout << "Inserting a 3 and a 81" << std::endl; 
    a.insert(3);
    a.insert(81);
        
    list1 = buildList(a);
    std::cout << "Printing out new list: ";
    list1.forEach(print<int>);
    std::cout << std::endl;
    std::cout << "Printing out Deep Copy: ";
    list2.forEach(print<int>);
    return EXIT_SUCCESS;
}
