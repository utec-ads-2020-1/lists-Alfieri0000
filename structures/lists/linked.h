#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {};
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
            if (empty()){
                throw out_of_range("List is Empty");
            }
            if (size()==1){
                this->head = nullptr;
                this->tail = nullptr;
            }
            else{
                Node<T>* temp;
                temp = this->head;
                this->head = temp->next;
                this->head->prev = nullptr;

                //Tengo que borrar lo que apunta head, guardado en temp?
                //delete temp;
            }
            this->nodes--;
        };
        void pop_back(){
            if (empty()){
                throw out_of_range("List is Empty");
            }
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
            if (empty()){ // No sería necesario
                throw out_of_range("List is Empty");
            }
            // Se puede hacer más eficiente
            LinkedList<T> tempReemplazo;
            for(int i = size()-1; i >= 0;i--){
                tempReemplazo.push_back(operator[](i));
            }
            clear();

            for(int i = 0 ; i<tempReemplazo.size(); i++){
                push_back(tempReemplazo.operator[](i));
            }
        };

        BidirectionalIterator<T> begin(){
            BidirectionalIterator <T> temp(this->head);
            return temp;
        };
	    BidirectionalIterator<T> end(){
            BidirectionalIterator <T> temp(this->tail->next);
            return temp;
        };

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
        void merge(LinkedList<T>& X){
            if (X.empty()){
                throw out_of_range("List is Empty");
            }
            Node<T>* temp;
            temp = X.head;
            //while(temp->next != false){ // Esta comparación no se puede hacer
            while(temp->next){
                push_back(temp->data);
                temp = temp->next;
            }
            push_back(temp->data);
            this->tail = temp;
            X.clear();
        };



         //Función Bubble sort para ordenar
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