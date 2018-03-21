#include "Library.h"
#include "Employee.h"
#include<iostream>
#include<iterator>

using namespace std;


// Creates a book object and inserts it into the archieved books array
void Library::addBook(string bookName) {
	if (bookName == "")
		throw invalid_argument("Error: empty string");

	// Push book to archieved books vector
	archBooks.push_back(bookName);
}


// Adds employee to the class and inserts employee into the queue of any books that are curently circulating*/
void Library::addEmployee(string Name) {
	if (Name == "")
		throw invalid_argument("Error: empty string");
	Employees.push_back(new Employee(Name));

	// Adds employee to any queues that are active
	if (!circBooks.empty()) {
		Employee *emp = Employees[Employees.size() - 1];
		for (size_t i = 0; i < circBooks.size(); i++) {
			circBooks[i].push(emp, (emp->waitingTime - emp->retaintingTime));
		}
	}
}

// Moves an archieved book into circulation and loads its queue
void Library::circulateBook(string title, Date startDate) {
	for (size_t i = 0; i < archBooks.size(); i++) {
		//title is searched for in arhcived books
		if (archBooks[i].get_title() == title) {
			circBooks.push_back(archBooks[i]);
			circBooks[circBooks.size() - 1].set_startDate(startDate);
			archBooks.erase(archBooks.begin() + i);
			//the employee priority for books in circulation is updated
			for (size_t j = 0; j < Employees.size(); j++)
				circBooks[circBooks.size() - 1].push(Employees[j], getPriority(Employees[j]));
			return;
		}
	}
	// If the loop exits normally, then the book does not exist
	throw invalid_argument("Error: title not found");
}

// Pass book on to the next person and return bool value for if the book was passed on
bool Library::pass_on(string title, Date curdate)
{
	for (size_t i = 0; i < circBooks.size(); i++) {
		if (circBooks[i].get_title() == title) {
			Employee* prev_holder = circBooks[i].getHolder();
			// Tests for if there is anyone left to pass to
			if (circBooks[i].pass_on(curdate)) {
				update_queues(prev_holder);
				return true;
			}
			// If no one left to pass to, archieve the book
			else {
				update_queues(prev_holder);
				circBooks[i].set_endDate(curdate);
				archBooks.push_back(circBooks[i]);
				circBooks.erase(circBooks.begin() + (i));
				return false;
			}
		}
	}
	//if this point is reached the title does not exist
	throw invalid_argument("Error: Title does not exist");
}


// Updates all book queues In which the given employee is located
void Library::update_queues(Employee* e) {
	for (int i = 0; i < circBooks.size(); i++) {
		if (circBooks[i].contains(e)) {
			circBooks[i].update(e, e->waitingTime - e->retaintingTime);
		}
	}
}
//returns priority
int Library::getPriority(Employee* emp) {
	return emp->waitingTime - emp->retaintingTime;
}

