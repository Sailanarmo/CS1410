#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <memory>
#include <functional>

template<typename T>
struct Node{

    //Node* prev;
    T data;
    Node(T t, std::shared_ptr<Node> l = nullptr) : data(t), next(l){}
    std::shared_ptr<Node> next;

};



template<typename T>
void forEachR(std::shared_ptr<Node<T>> list,void(*f)(const T &)){
    if (!list) return;
    f(list -> data);
    forEachR (list -> next, f);
}

template<typename T>
std::shared_ptr<Node<T>> clone(std::shared_ptr<Node<T>> list){

    if(!list) return nullptr;
    return std::make_shared<Node<T>>(list->data, clone(list->next));
    //node -> data = list->data;
    //node -> prev = prev;
    //node -> next = clone(list -> next/*, node.get()*/);
    //return node;

}    

template<typename T>
void insertR(std::shared_ptr<Node<T>>& list, T data){
    if(!list){
	list = std::make_shared<Node<T>>(data);
    }
    else if(list->data > data){
	auto temp  = std::make_shared<Node<T>>(data, list);
	list = temp;
    }
    else {
	insertR(list->next, data);
    }
}

template<typename T>
void removeR(std::shared_ptr<Node<T>>& list, T target){
    if(!list) return;
    if(target == list-> data)
    {
        list = list -> next;
    }
    else
    {
	removeR(list->next, target);
    }
}

template<typename T>
int sizeR(std::shared_ptr<Node<T>> pos){
    if(!pos) return 0;
    return 1 + sizeR(pos->next);
}
 
template<typename T>
class LinkedList{

public:

    LinkedList() : head(nullptr){};
    LinkedList(LinkedList const & original) : head(clone(original.head)){}
    LinkedList(LinkedList const && original) : head(original.head){}
    LinkedList& operator=(LinkedList & original) {head = clone(original.head); return *this; }
    LinkedList& operator=(LinkedList && original) {head = original.head; return *this; }
    void insert(T t) { insertR(head, t); }
    void remove(T t) { removeR(head, t); }
    int size() { return sizeR(head); } 
    template<typename F>
    void forEach(F f) { forEachR(head, f); }
private:

    std::shared_ptr<Node<T>> head;

}; 


#endif
