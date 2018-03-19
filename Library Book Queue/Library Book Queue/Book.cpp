#include "Book.h"
#include "Priority_Queue.h"

Book::Book() : title("") {}

Book::Book(std::string s) : title(s) {}

Book::Book(Book& other) {
	*this = other;
}

bool Book::pass_on(Date curdate) {
	//if an employee does have the book,employees rtime is updated
	if (emp_with_book != nullptr) {
		emp_with_book->retaintingTime = last_pass - curdate;
		last_pass = curdate;
		//if queue is not empty, book wielder is set to person at the front of the queue
		if (!queue.isempty()) {
			emp_with_book = queue.get_front();
			queue.pop();
			//book wielder wait time is set by subtracting current date from the start date
			emp_with_book->waitingTime = curdate - start_date;
			//return true after successful pass on
			return true;
		}
		else {
			//if queue is empty, book wielder is null
			emp_with_book = nullptr;
			return false;
		}
	}
	else {
		//if book wielder is null and the queuue is not empty, book wielder is set to the person in the fron to the queue
		if (!queue.isempty()) {
			emp_with_book = queue.get_front();
			queue.pop();
			return true;
		}
		else {
			//if book wielder is null but queue is not empty, there has been an error
			throw invalid_argument("Error: Employee could not be found");
		}
	}
}
//pushes employee and their priority into queue
void Book::push(Employee* e, int p){
	queue.push(e, p);
}
//checks to see if employee holds book
bool Book::contains(Employee* emp) {
	return queue.search(emp);
}

void Book::set_title(std::string t) { title = t; }

std::string Book::get_title() { return title; }
//initalies start date and last pass for book
void Book::set_startDate(Date s) { 
	start_date = s; 
	last_pass = s;
}

Date Book::get_startDate() { return start_date; }


void Book::set_lastPass(Date l) { last_pass = l; }


Date Book::get_lastPass() { return last_pass; }


void Book::set_endDate(Date e) { end_date = e; }


Date Book::get_endDate() { return end_date; }


Employee* Book::getHolder() { return emp_with_book; }

//calls queues update method, updates employees priority in queue
void Book::update(Employee* e, int p) {
	queue.update(e, p);
}

//copy constructor override
Book& Book::operator=(Book& RHS) {
	title = RHS.title;
	start_date = RHS.start_date;
	last_pass = RHS.last_pass;
	end_date = RHS.end_date;
	emp_with_book = RHS.emp_with_book;
	while (!queue.isempty())
		queue.pop();
	return *this;
}
