#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class ForwardIterator {
    private:
        Node<T> *current;

    public:
        ForwardIterator(
        );
        ForwardIterator(Node<T>* t){
            this->current = t;
        };

        ForwardIterator<T> operator=(ForwardIterator<T> t){
            this->current = t->current;
        };

        bool operator!=(ForwardIterator<T> t){
            return this->current != t.current;
        };

        ForwardIterator<T> operator++(){
            this->current = this->current->next;
        };

        T operator*(){
            return this->current->data;
        };
};

#endif