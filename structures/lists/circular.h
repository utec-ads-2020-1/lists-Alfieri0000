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
            if (empty()){
                throw out_of_range("List is Empty");
            }
            else if(size()==1){
                return this->head->data;
            }
            else{
                return this->head->prev->data;
            }
        };
        void push_front(T t){
            Node<T>* temp = new Node<T>;
            temp->data = t;
            if(empty()){
                this->head = temp;
            }
            else if(size() == 1){
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
                
                //Actualizo al Next del Prev de head
                this->head->prev->next = temp;

                //Actualizo el prev de head
                this->head->prev = temp;
                
                //Actualizo head
                this->head = temp;
            }
            this->nodes++;
        };
        void push_back(T t){
            Node<T>* temp = new Node<T>;
            temp->data = t;
            if(empty()){
                this->head = temp;
            }
            else if(size() == 1){
                this->head->prev = temp;
                this->head->next = temp;
                temp->next = this->head;
                temp->prev = this->head;
            }
            else{
                //Inserto temp
                temp->prev = this->head->prev;
                temp->next = this->head;
                
                //Actualizo el Next del Prev de head
                this->head->prev->next = temp;

                //Actualizo el Prev de Head
                this->head->prev = temp;
                
            }
            this->nodes++;
        };
        void pop_front(){
            if (empty()){
                throw out_of_range("List is Empty");
            }
            if (size()==1){
                this->head = nullptr;
            }
            else if(size() == 2){
                this->head = this->head->next;
                this->head->next = nullptr;
                this->head->prev = nullptr;
            }
            else{
                Node<T>* temp;
                temp = this->head;

                //Actualizo el siguiente de Head
                this->head->next->prev = this->head->prev;

                //Actualizo el anterior a Head
                this->head->prev->next = this->head->next;

                //Actualizo el head
                this->head = temp->next;

            //Tengo que borrar lo que apunta head, guardado en temp?
            }
            this->nodes--;
        };
        void pop_back(){
            if (empty()){
                throw out_of_range("List is Empty");
            }
            if (size()==1){
                this->head = nullptr;
            }
            else if (size()==2){
                this->head->next = nullptr;
                this->head->prev = nullptr;
            }
            else{
                Node<T>* temp;
                temp = this->head->prev;

                //Actualizo el anterior del anterior de Head y Head
                this->head->prev = this->head->prev->prev;
                temp->next = this->head;
            }
            this->nodes--;
            //Tengo que borrar lo que apunta Prev head?
        };
        T operator[](int t){
            if (empty()){
                throw out_of_range("List is Empty");
            }
            if (t >= size() || t < 0){
                throw out_of_range("Dato fuera de Rango");
            }
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
            if (empty()){
                throw out_of_range("List is Empty");
            }
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
            int tam = size();
            T temp[tam];
            for(int i = 0;i<tam;i++){
                temp[i] = operator[](i);
            }

            clear();

            for(int i = tam-1; i >= 0;i--){
                push_back(temp[i]);
            }

        };

        void print(){
            cout << "Head -> ";
            for(int i = 0;i<size();i++){
                cout << operator[](i) << ", ";
            }
        }

        BidirectionalIterator<T> begin(){
            BidirectionalIterator <T> temp(this->head);
            return temp;
        };
	    BidirectionalIterator<T> end(){
            BidirectionalIterator <T> temp(this->head->prev);
            return temp;
        };

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
            for(int i = 0;i<t.size();i++){
                push_back(t.operator[](i));
            }
            t.clear();

        };


        void swap(T *A, T *B)  
        {  
            T temp = *A;  
            *A = *B;  
            *B = temp;  
        }  
        void bubbleSort(T datos[], int tam)  
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