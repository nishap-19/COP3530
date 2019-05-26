/*
Fall 2018, COP3530.01 Data Structures and Algorithms
Homework 2
Purpose:
A.	Write a linear search algorithm to find an element (key) in an array
Student Name: Nisha Patel
*/

using namespace std;
#include <iostream>
#include <string>

int main(){
	
	int n[] = { 13,1,7,4,3,2 };
	int key = 3;
	bool found = 0;
	int location = 1;

	for (int x = 0; x < sizeof(n) & found==0; x++, location++) {
		if (n[x] == key)
			found = 1;
	}

	if (found == 1)
		cout << "The key of " << key << " was found at location " << location
			<< " of the array" << endl;
	else
		cout << "The key of " << key << " was not found." << endl;
}