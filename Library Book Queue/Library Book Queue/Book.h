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
	*/

class Book
{
private:
	Date start_date, last_pass, end_date;
	string title;
	Priority_Queue queue;
	Employee* emp_with_book;
public:
	Book();
	Book(string name);
	Book(Book&);

	bool pass_on(Date);
	void push(Employee* e, int priority);
	bool contains(Employee* emp);
	void update(Employee* e, int p);
	Book& operator=(Book& rhs);
	// Getters and Setters
	void set_title(string);
	string get_title();
	void set_startDate(Date);
	Date get_startDate();
	void set_lastPass(Date);
	Date get_lastPass();
	void set_endDate(Date);
	Date get_endDate();
	Employee* getHolder();

};
