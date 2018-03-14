#pragma once
#include"Date.h"
#include"Employee.h"
#include<vector>
using namespace std;

class Book
{
private:
	Date start_date;
	Date end_date;
	string name;
	Employee* priority_queue;
	Employee* emp_with_book;
protected:
	void pass_on(Date curdate);
public:
	void set_name(string n) {name = n;}
	string get_name() {return name;}
};
