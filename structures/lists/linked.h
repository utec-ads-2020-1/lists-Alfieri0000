#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
#include <assert.h>

// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {
            this->head = nullptr;
            this->tail = nullptr;
            this->nodes = 0;
        }
        T front(){
            assert(empty() == false);
            return this->head->data;
        };
        T back(){
            assert(empty() == false);
            return this->tail->data;
        };
        void push_front(T t){
            Node<T>* temp = new Node<T>;
            temp->data = t;
            if(empty()){
                this->head = temp;
                this->tail = temp;
            }
            else{
                this->head->prev = temp;
                temp->next = this->head;
                this->head = temp;
            }
            this->nodes++;
        };
        void push_back(T t){
            Node<T>* temp = new Node<T>;
            temp->data = t;
            if(empty()){
                this->head = temp;
                this->tail = temp;
            }
            else{
                this->tail->next = temp;
                temp->prev = this->tail;
                this->tail = temp;
            }
            this->nodes++;
        };
        void pop_front(){
            assert(empty() == false);
            if (size()==1){
                this->head = nullptr;
                this->tail = nullptr;
            }
            else{
                Node<T>* temp;
                temp = this->head;
                this->head = temp->next;
                this->head->prev = nullptr;
                this->nodes--;

                //Tengo que borrar lo que apunta head, guardado en temp?
                //delete temp;
            }
            this->nodes--;
        };
        void pop_back(){
            assert(empty() == false);
            if (size()==1){
                this->head = nullptr;
                this->tail = nullptr;
            }
            else{
                Node<T>* temp;
                temp = this->tail;
                this->tail = temp->prev;
                this->tail->next = nullptr;
            }
            this->nodes--;
            //Tengo que borrar lo que apunta head, guardado en temp?
            //delete temp;
        };
        T operator[](int t){
            assert(empty() == false);
            Node<T>* temp;
            temp = this->head;
            for(int i = 0;i<t;i++){
                temp = temp->next;
            }
            return temp->data;
        };
        bool empty(){
            return this->nodes == 0;
        };
        int size(){
            return this->nodes;
        };
        void clear(){
            while(!empty()){
                pop_front();
            }
        };
        
        void sort(){
            int a;
        };
        void reverse(){
            int a;
        };

        // BidirectionalIterator<T> begin();
	    // BidirectionalIterator<T> end();

        string name() {
            return "Linked List";
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
        void merge(LinkedList<T>&){
            int a;
        };
};

#endif