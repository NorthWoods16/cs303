#include "Library.h"
#include "Employee.h"
#include<iostream>
#include<iterator>

using namespace std;

/*TODO 
	Add exceptions where they belong
*/
//adds book to archbooks
void Library::addBook(string bookName) {
	//checks that book title passed in is valid
	if (bookName == "")
		//error thrown if string is empty
		throw invalid_argument("Error: empty string");
	//new book class instance declared
	Book newBook;
	//set title method is called to declare book title
	newBook.set_title(bookName);
	//book class instance is added to vector archBooks
	archBooks.push_back(newBook);
}
//adds an employee to employee vector
void Library::addEmployee(string Name) {
	//passed in employee name is checked to see if its not empty
	if (Name == "")
		//if string is empty error is thrown
		throw invalid_argument("Error: empty string");
	//new employee instance is created
	Employee newEmp;
	//employeee name is added
	newEmp.name = Name;
	//checks to see if there are any circulating books
	if (!circBooks.empty()) {
		//the employee is added to the circBook vector
		for (unsigned int i = 0; i < circBooks.size(); i++) {
			circBooks[i].push(&newEmp, (newEmp.waitingTime - newEmp.retaintingTime));
		}
	}
}
//takes archived book and puts it into circluation
void Library::circulateBook(string title, Date startDate) {
	//new book instance is declared
	Book newBook;
	//if boolean found remains false after searching archbooks vector the book passed in an error is thrown
	bool found = false;
	//arch books searched for book passed in
	for (unsigned int i = 0; i < archBooks.size(); i++) {
		if (archBooks[i].get_title() == title) {
			//if title is found book is initialzed using passed in title and date
			newBook.set_title(archBooks[i].get_title());
			newBook.set_startDate(startDate);
			circBooks.push_back(newBook);
			//book is removed from archived books
			archBooks.erase(archBooks.begin() + (i - 1));
			//boolean found is set to true so error message is not thrown
			found = true;
			break;
		}
		if (i == (archBooks.size() - 1) && !found) {
			//if the title is not found in the archived books vector than the book does not exist and an error is thrown
			throw invalid_argument("Error: title not found");
		}
	}

}
//circulating book will be passed on to the next person 
bool Library::pass_on(string title, Date curdate) {
	//book is located in circbooks vector
	for (size_t i = 0; i < circBooks.size(); i++) {
		if (circBooks[i].get_title() == title) {
			Employee* prev_holder = circBooks[i].getHolder();
			if (circBooks[i].pass_on(curdate)) {
				update_queues(prev_holder);
				return true;
			}
			else {
				//book changes hands
				update_queues(prev_holder);
				circBooks[i].set_endDate(curdate);
				archBooks.push_back(circBooks[i]);
				circBooks.erase(circBooks.begin() + (i - 1));
				return false;
			}
		}
	}
	//if book is not found in circulating book an error is thrown
	throw invalid_argument("Error: Title does not exist");
}
//updates book queues
void Library::update_queues(Employee* e) {
	for (int i = 0; i < circBooks.size(); i++) {
		//checks in circBooks for employee passed in
		if (circBooks[i].contains(e)) {
			//book method update is called an waiting times are updated
			circBooks[i].update(e, e->waitingTime - e->retaintingTime);
		}
	}
}

