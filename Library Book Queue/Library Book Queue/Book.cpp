#include "Book.h"
#include "Priority_Queue.h"

/*TODO
Clean all functions
Test all functions*/
Book::Book() : title("") {}

Book::Book(std::string s) : title(s), emp_with_book(nullptr) {}

Book::Book(const Book& other) {
	*this = other;
}

// Passes the book on to the next person in the queue
bool Book::pass_on(Date curdate) {

	// Raise error if no one to pass on to
	if (emp_with_book == nullptr)
		throw invalid_argument("Error: No current holder exists");

	// If none of the above conditions are met, pass the book on normally
	emp_with_book->retaintingTime = curdate - last_pass;
	last_pass = curdate;

	if (!queue.isempty()) {
		emp_with_book = queue.get_front();
		queue.pop();
		emp_with_book->waitingTime = curdate - start_date;
		return true;
	}
	else {
		emp_with_book = nullptr;
		return false;
	}
}

// Pushes employee into the queue
void Book::push(Employee* e, int p) {
	if (emp_with_book == nullptr)
		emp_with_book = e;
	else
		queue.push(e, p);
}

// Returns bool for if employee is in the queue
bool Book::contains(Employee* emp) {

	return queue.search(emp);

}

// Sets the start date
void Book::set_startDate(Date s) {
	start_date = s;
	last_pass = s;
}

// Updates the priority of an item in the book's queue
void Book::update(Employee* e, int p) {
	queue.update(e, p);
}

// Assignment operator
Book& Book::operator=(const Book& RHS) {
	title = RHS.title;
	start_date = RHS.start_date;
	last_pass = RHS.last_pass;
	end_date = RHS.end_date;
	emp_with_book = RHS.emp_with_book;
	queue = RHS.queue;
	return *this;
}
