#ifndef STACK_H
#define STACK_H

using namespace std;

#include <assert.h> 

#define MAX 1000 

// TODO: Implement all methods
template <typename T>
class stack {
	T* data;
	int top;
	int capacity;

public:
	stack(int size = MAX){
		this->data = new T[size];
		this->capacity = size;
		this->top = 0;
	};
	~stack(){
		delete[] this->data;
	};   		

	void push(T t){
		if (full()){
			resize();
		}
		this -> data[top] = t;
		this -> top++;
	};

	void pop(){
		assert(empty() == false);
		this->top--;
	};

	T peak(){
		assert(empty() == false);
		return this->data[top-1];
	};

	int size(){
		return this->top;
	};
	bool empty(){
		return top == 0;
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