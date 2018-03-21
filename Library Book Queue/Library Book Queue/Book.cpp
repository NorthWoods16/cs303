#include "Book.h"
#include "Priority_Queue.h"

Book::Book() : title("") {}

Book::Book(std::string s) : title(s) {}

Book::Book(const Book& other) {
	*this = other;
}

bool Book::pass_on(Date curdate) {
	if (emp_with_book != nullptr) {
		emp_with_book->retaintingTime = last_pass - curdate;
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
	else {
		if (!queue.isempty()) {
			emp_with_book = queue.get_front();
			queue.pop();
			return true;
		}
		else {
			throw invalid_argument("Error: Employee could not be found");
		}
	}
}

void Book::push(Employee* e, int p){
	queue.push(e, p);
}

bool Book::contains(Employee* emp) {

	return queue.search(emp);

}

void Book::set_title(std::string t) { title = t; }

std::string Book::get_title() { return title; }

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

void Book::update(Employee* e, int p) {
	queue.update(e, p);
}


Book& Book::operator=(const Book& RHS) {
	title = RHS.title;
	start_date = RHS.start_date;
	last_pass = RHS.last_pass;
	end_date = RHS.end_date;
	emp_with_book = RHS.emp_with_book;
	while (!queue.isempty())
		queue.pop();
	return *this;
}
