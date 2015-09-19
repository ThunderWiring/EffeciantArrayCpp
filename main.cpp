/*
 * main.cpp
 *
 *  Created on: 2 April 2015
 *      Author: bassam
 */

#include "array.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
int main() {
	Array<int> array = Array<int>(10);
	array.print();
	/*initialize:*/
	array[2] = 22;
	array[1] = 13;
	std::cout << "--------------------------------------------------------\n";
	array.print();
	return 0;
}
