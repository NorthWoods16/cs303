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
	Merge with updated version of priority_queue
	add Exceptions
	define contains
	change everything to nullptr
	*/

class Book
{
private:
	Date start_date, last_pass, end_date;
	std::string title;
	Priority_Queue queue;
	Employee* emp_with_book;
public:
	Book();
	Book(std::string);
	Book(Book&);

	bool pass_on(Date);
	void push(Employee*, int priority);
	bool contains(Employee*);
	void update(Employee*, int p);
	Book& operator=(Book& rhs);
	// Getters and Setters
	void set_title(std::string);
	std::string get_title();
	void set_startDate(Date);
	Date get_startDate();
	void set_lastPass(Date);
	Date get_lastPass();
	void set_endDate(Date);
	Date get_endDate();
	Employee* getHolder();

};
