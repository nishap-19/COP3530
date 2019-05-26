/*
Fall 2018, COP3530.01 Data Structures and Algorithms
Homework 1
Purpose:
Using only pointers (no array indexing), write
I.	A function to add all numbers in an integer array.
II.	A function to remove all odd numbers from an ordered array. The array should remain ordered. Would it be easier to write this function if the array were unordered?
Student Name: Nisha Patel
*/

using namespace std;
#include <iostream>
#include <string>
#include <stdio.h>

//finds the total sum of all the elements in the array
int totalValue(int *arr, int totalSize) {

	int sum = 0;	//instantiates variable to hold total sum value

	//run through each memory location for the array
	for (int y = 0; y < totalSize; y++) {
		//add the value at each memory location of the array to the total sum variable
		sum = sum + *(arr+y);
	}
	return sum;
}

//removes any odd integer in the array
void removeOdd(int *arr, int totalSize) {

	//run through each memory location for the array
	for (int y = 0; y < totalSize; y++) {
		//check each value of the array to see if it odd
		if (*(arr + y) % 2 == 1) {
			//changes the value of the odd value to zero
			*(arr + y) = 0;
		}
		
	}
}

//prints out each value in the array
void printArray(int *arr, int totalSize) {

	int size = totalSize;

	//run through each memory location for the array
	for (int y = 0; y < size; y++) {
		//prints out each value in the array
		cout << *(arr + y) << ' ';
	}
}

int main() {

	int p[] = {12, 9, 8, 3, 11, 7};

	cout << "Total Sum of the Array: ";
	cout << totalValue(p, 6);
	cout << endl;
	removeOdd(p, 6);
	cout << "Array Values: ";
	printArray(p, 6);
	cout << endl;

	system("pause");
}