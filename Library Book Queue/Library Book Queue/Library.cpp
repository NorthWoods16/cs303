#include "Library.h"
#include "Employee.h"
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

/*TODO 
	Add exceptions where they belong
	define update_queues*/

void Library::addBook(string bookName) {
	if (bookName == "")
		throw invalid_argument("Error: empty string");
	Book newBook;
	newBook.set_title(bookName);
	archBooks.push_back(newBook);
}

void Library::addEmployee(string Name) {
	if (Name == "")
		throw invalid_argument("Error: empty string");
	Employee newEmp;
	newEmp.name = Name;
	// If there are currently books in the circulating books vector, place a pointer to the employee into the book’s queue by calling the book class’s push function
}

void Library::circulateBook(string title, Date startDate) {
	Book newBook;
	bool found = false;
	for (unsigned int i = 0; i < archBooks.size(); i++) {
		if (archBooks[i].get_title() == title) {
			newBook.set_title(archBooks[i].get_title());
			newBook.set_startDate(startDate);
			circBooks.push_back(newBook);
			archBooks.erase(archBooks.begin() + (i - 1));
			found = true;
			break;
		}
		if (i == (archBooks.size() - 1) && !found){
			throw invalid_argument("Error: title not found");
		}
	}
}

bool Library::pass_on(string title, Date curdate) {
	for (size_t i = 0; i < circBooks.size(); i++) {
		if (circBooks[i].get_title() == title) {
			Employee* prev_holder = circBooks[i].getHolder();
			if (circBooks[i].pass_on(curdate)) {
				update_queues(prev_holder);
				return true;
			}
			else {
				update_queues(prev_holder);
				circBooks[i].set_endDate(curdate);
				archBooks.push_back(circBooks[i]);
				circBooks.erase(circBooks.begin() + (i - 1));
				return false;
			}
		}
	}
	//throw error if iteration reaches here
}


void Library::update_queues(Employee* e) {
	for (int i = 0; i < circBooks.size(); i++) {
		if (circBooks[i].contains(e)) {
			circBooks[i].update(e);
		}
	}
}
