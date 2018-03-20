#pragma once
#include"Date.h"
#include "Priority_Queue.h"
#include"Employee.h"
#include<vector>
/*What has changed
	added declarations for contains, update, and assignment operator
	defined assignment operator
*/

/* TODO
	add Exceptions
	define contains
	change everything to nullptr
	*/

class Book
{
private:
	Date start_date, last_pass, end_date;
	string title;
	Priority_Queue queue;
	Employee* emp_with_book;
public:
	// Constructors
	Book();
	Book(std::string name);
	Book(const Book&);

	bool pass_on(Date);
	void push(Employee* e, int priority);
	bool contains(Employee* emp);
	void update(Employee* e, int p);
	Book& operator=(const Book& rhs);

	// Getters and Setters
	void set_title(std::string t) { title = t; }

	string get_title() { return title; }

	// 
	void set_startDate(Date); // Has multiple lines, defined in cpp

	// Returns the date the book went into circulation
	Date get_startDate() { return start_date; }

	// Allows for updating of the last pass date
	void set_lastPass(Date last) { last_pass = last; }

	// Returns the last date the book was passed on
	Date get_lastPass() { return last_pass; }

	// Allows for updating the end Date
	void set_endDate(Date end) { end_date = end; }

	// Returns the enddate for when the book was archieved
	Date get_endDate() { return end_date; }

	// Returns a pointer to the employee who is holding the book
	Employee* getHolder() { return emp_with_book; }

};
