#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator();
        BidirectionalIterator(Node<T>* t){
            this->current = t;
        };

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> t){
            this->current = t->current;
            // No hay return
        };

        bool operator!=(BidirectionalIterator<T> t){
            return this->current != t.current;
        };

        BidirectionalIterator<T> operator++(){
            this->current = this->current->next;
            // No hay return, y si current es null?
        };

        BidirectionalIterator<T> operator--(){
            this->current = this->current->prev;
            // No hay return, y si current es null?
        };

        T operator*(){
            // Si current es null?
            return this->current->data;
        };
};

#endif