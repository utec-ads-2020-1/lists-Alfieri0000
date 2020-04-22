#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

using namespace std;

// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {
        }
        T front(){
            if (empty()){
                throw out_of_range("List is Empty");
            }
            return this->head->data;
        };
        T back(){
            front();
        };
        void push_front(T t){
            Node<T>* temp = new Node<T>;
            temp->data = t;
            if(empty()){
                this->head = temp;
            }
            else if(this->nodes == 1){
                this->head->prev = temp;
                this->head->next = temp;
                temp->next = this->head;
                temp->prev = this->head;
                this->head = temp;
            }
            else{
                //Inserto temp
                temp->next = this->head;
                temp->prev = this->head->prev;
                
                //Actualizo al prev de head
                this->head->prev->next = temp;
                
                //Actualizo head
                this->head = temp;
            }
            this->nodes++;
        };
        void push_back(T t){
            int a;
        };
        void pop_front(){
            int a;
        };
        void pop_back(){
            int a;
        };
        T operator[](int t){
            return 1;
        };
        bool empty(){
            return this->nodes == 0;
        };
        int size(){
            return this->nodes;
        };
        void clear(){
            int a;
        };
        void sort(){
            int a;
        };
        void reverse(){
            int a;
        };

        //BidirectionalIterator<T> begin();
	    //BidirectionalIterator<T> end();

        string name() {
            return "Circular Linked List";
        }

        /**
         * Merges x into the list by transferring all of its elements at their respective 
         * ordered positions into the container (both containers shall already be ordered).
         * 
         * This effectively removes all the elements in x (which becomes empty), and inserts 
         * them into their ordered position within container (which expands in size by the number 
         * of elements transferred). The operation is performed without constructing nor destroying
         * any element: they are transferred, no matter whether x is an lvalue or an rvalue, 
         * or whether the value_type supports move-construction or not.
        */
        void merge(CircularLinkedList<T>& t){
            int a;
        };
};

#endif