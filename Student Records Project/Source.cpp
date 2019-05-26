/*
Fall 2018, COP3530.01 Data Structures and Algorithms
Project 1
Purpose:
Create a student record object that contains
-first and last name, course number, section
Create linked lists to store student record data
Be able to access student records
-add records, delete record, modify records
Student Name: Nisha Patel
*/

#include <iostream>
#include <string>
using namespace std;

//creates struct object
struct Records {
	string firstName, lastName, courseNum, sectionNum;
	Records *next;
};

//checks if the first pointer is empty or points to a value
bool empty(Records *head) {
	if (head == NULL)
		return true;
	else
		return false;
}

//creates a new Records node to add new student data to the linked list
void addRecord(Records *&head, Records *&tail, string first, string last, string course, string section) {
	Records *temp = new Records;
	temp->firstName = first;
	temp->lastName = last;
	temp->courseNum = course;
	temp->sectionNum = section;
	temp->next = NULL;
	
	//checks if the linked list is null
	if (empty(head)) { //sets new node to head and tail pointers
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp; //adds new node after the last record
		tail = temp;	//shifts tail to point to new last node in list
	}
}

//prints out all the student record nodes
void printRecords(Records *record) {
	if (empty(record)) //checks to see if the list of records is empty
		cout << "No records found" << endl;
	else {
		cout << "The Student Records are: \n";

		int recordNum = 1;

		while (record != NULL) { //goes from node to node in the list to print each record until the end of the list is reached
			cout << "Record ";
			cout << recordNum << endl;
			cout << "Student Name: " + record->firstName + " " + record->lastName +
				"\t Course Number: " + record->courseNum + "\t Section Number: " +
				record->sectionNum << endl;
			record = record->next;
			recordNum++;
		}
		cout << endl;
	}
}

//edit a student record node
void editRecord(Records *record) {
	Records *temp = record;
	bool searching = true;
	string first, last;
	int option;

	cout << "Enter the student's first name: ";
	cin >> first;
	cout << "Enter the student's last name: ";
	cin >> last;

	//travels down nodes in list until student is found
	while (searching && temp != NULL) {
		if (temp->firstName == first && temp->lastName == last) {
			searching = false;
		}
		else
			temp = temp->next;
	}
	cout << endl;

	if (searching)
		cout << "Student does not exist" << endl;

	while (!searching) {
		//prompts user to input choice for record edit
		cout << "1. Edit First Name"
			<< "\n2. Edit Last Name"
			<< "\n3. Edit Course Number"
			<< "\n4. Edit Section Number"
			<< "\n5. Exit Record"
			<< "\n\nSelect You Choice: ";
		cin >> option;
		cout << endl;

		string firstN, lastN, courseN, sectionN;

		//takes user's edit choice and performs edit by reassigning new value to record field
		switch (option) {
		case 1:
			cout << "Enter the first name: ";
			cin >> firstN;
			temp->firstName = firstN;
			cout << endl;
			break;
		case 2:
			cout << "Enter the last name: ";
			cin >> lastN;
			temp->lastName = lastN;
			cout << endl;
			break;
		case 3:
			cout << "Enter the course number: ";
			cin >> courseN;
			temp->courseNum = courseN;
			cout << endl;
			break;
		case 4:
			cout << "Enter the section number: ";
			cin >> sectionN;
			temp->sectionNum = sectionN;
			cout << endl;
			break;
		case 5:
			cout << "Exiting Record Updator..." << endl;
			searching = true;
			break;
		default:
			cout << "Invalid selection" << endl;
		}
	}
}

//delete a student node
void deleteRecord(Records *&head, Records *&tail, string first, string last) {
	if (empty(head))
		cout << "No records found" << endl;
	else {
		Records *current = head;
		Records *previous = head;
		
		while (current != NULL) { //iterates through the nodes until the last record is reached
			//validates if the record is found by comparing first and last name
			if ((current->firstName == first) && (current->lastName == last)) {
				if (current->next == NULL) {
					previous->next = NULL;
					tail = previous;	//reassigns the tail node to the record node before it
					delete current;		//removes the current node from memory
					cout << "Student Record deleted" << endl;
				}
				else {
					previous->next = current->next;	//the node at the previous pointer is set to point to the node after current
					cout << "Student record deleted" << endl;
					delete current;		//removes the current node from memory
				}
				break;
			}

			/*
			if (current == previous)
				current = current->next;
			else {
				current = current->next;
				previous = previous->next;
			}*/

			previous = current;
			current = current->next;
		}
		if (current == NULL)
			cout << "Student Record not found" << endl << endl;
	}
}

//search for a student record node
void searchRecord(Records *records) {
	Records *temp = records;
	bool searching = true;
	string first, last;

	cout << "Enter the student's first name: ";
	cin >> first;
	cout << "Enter the student's last name: ";
	cin >> last;
	cout << endl;

	//travels down nodes in list until student is found
	while (searching && temp != NULL) {
		if (temp->firstName == first && temp->lastName == last) {
			cout << "Student Name: " + temp->firstName + " " + temp->lastName +
				"\t Course Number: " + temp->courseNum + "\t Section Number: " +
				temp->sectionNum + "\n" << endl;
			searching = false;
		}
		temp = temp->next;
	}
	if (searching)
		cout << "Student Record not found" << endl << endl;
}

int main() {
	Records *head = NULL;
	Records *tail = NULL;
	string input;  char option;
	int active = 1;
	string firstN, lastN, courseN, sectionN;

	cout << "Welcome to the Student Records Database\n" << endl;

	while (active == 1) {
		//displays user options to use in database and prompts for their input
		cout << "1. Add Records"
			<< "\n2. List Records"
			<< "\n3. Modify Records"
			<< "\n4. Delete Records"
			<< "\n5. Search For A Student"
			<< "\n6. Exit Program"
			<< "\n\nSelect Your Choice: ";
		cin >> input;
		option = input.at(0); //ensures only one char is checked from user input
		cout << endl;

		switch (option) {
		case '1': //add a Student Record
			cout << "Enter the student's first name: ";
			cin >> firstN;
			cout << "Enter the student's last name: ";
			cin >> lastN;
			cout << "Enter their course number: ";
			cin >> courseN;
			cout << "Enter their section number: ";
			cin >> sectionN;
			addRecord(head, tail, firstN, lastN, courseN, sectionN);
			cout << endl;
			break;
		case '2': //print all Student Records
			printRecords(head);
			break;
		case '3': //edit a Student Record
			editRecord(head);
			cout << endl;
			break;
		case '4': //delete a Student Record
			cout << "Enter the student's first name: ";
			cin >> firstN;
			cout << "Enter the student's last name: ";
			cin >> lastN;
			cout << endl;
			deleteRecord(head, tail, firstN, lastN);
			cout << endl;
			break;
		case '5': //searches for a Student Record
			searchRecord(head);
			break;
		case '6': //exits the database
			active = 0;
			cout << "You have successfully exited the Student Records Database" << endl;
			break;
		
		default:
			cout << "Invalid selection" << endl << endl;
			break;
		}
	}
	return 0;
}