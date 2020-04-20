#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
//#include "iterators/forward_iterator.h"
#include "node.h"
#include <assert.h> 

using namespace std;

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        ForwardList() : List<T>() {
            this->head = nullptr;
        };

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
                temp->next = this->head;
                this->head = temp;
            }
        };
        void push_back(T t){
            Node<T>* tempEntry = new Node<T>;
            tempEntry->data = t;
            if(empty()){
                this->head = tempEntry;
                this->tail = tempEntry;
            }
            else{
                Node<T>* tempFinal;
                tempFinal = this->head;
                while(tempFinal->next!=nullptr){
                    tempFinal = tempFinal->next;
                }   
                tempFinal->next = tempEntry;
                this->tail = tempEntry;
            }

        };
        void pop_front(){
            assert(empty() == false);
            Node<T>* temp;
            temp = this->head;
            this->head = temp->next;

            //Tengo que borrar lo que apunta head, guardado en temp?
            //delete temp;
        };

        void pop_back(){
            assert(empty() == false);
            Node<T>* temp;
            temp = this->head;
            while(temp->next!=this->tail && this->tail != this->head){
                temp = temp->next;
            }

            this->tail = temp;
            temp->next = nullptr;

            //Tengo que borrar lo guardado en tail anteriormente?

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
            return this->head == nullptr;
        };
        int size(){
            if(empty()){
                return 0;
            }
            else{
                int count = 1;
                Node<T>* tempFinal;
                tempFinal = this->head;
                while(tempFinal->next!=nullptr){
                    tempFinal = tempFinal->next;
                    count++;
                }
                return count;
            }
        };
        void clear(){
            while(!empty()){
                pop_front();
            }
        };
        void sort(){

            int tam = size();
            T temp[tam];
            for(int i = 0;i<tam;i++){
                temp[i] = operator[](i);
            }

            int n = sizeof(temp)/sizeof(temp[0]);  
            bubbleSort(temp, n);

            clear();

            for(int i = 0 ; i<tam; i++){
                push_back(temp[i]);
            }


        };
        
        void reverse(){
            ForwardList<T> tempReemplazo;
            for(int i = size()-1; i >= 0;i--){
                tempReemplazo.push_back(operator[](i));
            }
            clear();

            for(int i = 0 ; i<tempReemplazo.size(); i++){
                push_back(tempReemplazo.operator[](i));
            }

        };

        //ForwardIterator<T> begin();
	    //ForwardIterator<T> end();

        string name() {
            return "Forward List";
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
        void merge(ForwardList<T>& X){
            assert(X.empty() == false);
            Node<T>* temp;
            temp = X.head;
            while(temp->next != false){
                push_back(temp->data);
                temp = temp->next;
            }
            push_back(temp->data);
            this->tail = temp;
            X.clear();
        }


        //Función Bubble sort para ordenar
        void swap(T *A, T *B)  
        {  
            T temp = *A;  
            *A = *B;  
            *B = temp;  
        }  
        void bubbleSort(T datos[], T tam)  
        {  
            int i, j;  
            for (i = 0; i < tam-1; i++) {
                for (j = 0; j < tam-i-1; j++){
                    if (datos[j] > datos[j+1]){
                        swap(&datos[j], &datos[j+1]);
                    }  
                }
            }    
        }
};

#endif