#include "Library.h"
#include "Employee.h"
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

void Library::addBook(string bookName) {
	if (bookName == "")
		throw invalid_argument("Error: empty string");
	Book newBook;
	newBook.set_name(bookName);
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
		if (archBooks[i].get_name() == title) {
			newBook.set_name(archBooks[i].get_name());
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

