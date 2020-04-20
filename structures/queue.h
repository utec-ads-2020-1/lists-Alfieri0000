#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

#include <assert.h> 

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class queue {
	T* data;
	int top;
	int capacity;

public:
	queue(int size = MAX){
		this -> data = new T[size];
		this -> top = 0;
		this -> capacity = size;
	};

	~queue(){
		delete[] this -> data;
	};   		

	void push(T t){
		if (full()){
			resize();
		}
		this->data[top] = t;
		top++;
	};

	void pop(){
		assert(empty() == false);
		//Copia
		T* temp = new T[capacity];
		for(int i=0;i<top;i++){
			temp[i] = this->data[i];
		}
		//Lleno de nuevo la queque pero con un dato atras
		for(int i=0;i<top-1;i++){
			this->data[i] = temp[i+1];
		}
		this->top--;

	};
	T front(){;
		assert(empty() == false);
		return this->data[0];
	}
    T back(){
		assert(empty() == false);
		return this->data[top-1];
	};

	int size(){
		return this->top;
	};
	bool empty(){
		return this->top == 0;
	};

//Funciones creadas
	bool full(){
		return this->top == this->capacity;
	}

	void resize(){
		T* temp = new T[capacity*2];
		for(int i=0;i<top;i++){
			temp[i] = this->data[i];
		}
		this->data = temp;
	}

};

#endif