/*
 * array.h
 *
 *  Created on: 2 באפר 2015
 *      Author: bassam
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
/***************************************************************/
template<typename T>
class Array {
private:
	int size;
	T* data;
	int top;
	T* stackArray;
	T* sideArray;
	const T GARBAGE = T();
	bool is_garbage(int index);
public:
	Array(int size);
	~Array();
	T operator[](const int index) const;
	T& operator[](const int index);
	void print() const;
};
/***************************************************************/
/*constructor*/
template<typename T>
Array<T>::Array(int s) : size(s), top(0) {
	data = new T[size];
	stackArray = new T[size];
	sideArray = new T[size];
}
/***************************************************************/
/*destructor*/
template<typename T>
Array<T>::~Array() {
	delete data;
	delete stackArray;
	delete sideArray;
}
/***************************************************************/
template<typename T>
T Array<T>::operator[](const int index) const {
	if(index > top) {
		return GARBAGE;
	} else if(stackArray[sideArray[index]] == index) {
		return data[index];
	}
	return GARBAGE;
}
/***************************************************************/
template<typename T>
T& Array<T>::operator[](const int index) {
	sideArray[index] = top;
	stackArray[top] = index;
	top++;
	return (data[index]);
}
/***************************************************************/
template<typename T>
void Array<T>::print() const {
	for(int i = size; i >= 0; --i) {
		std::cout << "data[" << i << "] = "<< data[i] <<
				"		, sideArray[" << i << "] = " << sideArray[i] <<
                "		, stackArray[" << i << "] = "<< stackArray[i]<< "\n";
	}
}



#endif /* ARRAY_H_ */
