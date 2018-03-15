#pragma once
#include"Date.h"
//#include "priority_queue"
#include"Employee.h"
#include<vector>
/*What has changed
	changed pass_on from void to bool
	Defined pass_on function
*/

/* TODO
	Merge with updated version of priority_queue
	define pass_on
	add push Function
	add Exceptions
	*/

class Book
{
private:
	Date start_date, last_pass, end_date;
	std::string title;
	//priority_queue<Employee*> queue;
	Employee* emp_with_book;
public:
	Book();
	Book(std::string);

	bool pass_on(Date);

	// Getters and Setters
	void set_title(std::string);
	std::string get_title();
	void set_startDate(Date);
	Date get_startDate();
	void set_lastPass(Date);
	Date get_lastPass();
	void set_endDate(Date);
	Date get_endDate();

};
