#pragma once
#include"Date.h"
#include"Employee.h"
#include"Book.h"
#include <vector>

/*What has changed
	moved pass_on from private to public
	changed pass on from void to bool
	updated pass_on to accept two parameters; title and current date
	added declaration for update queues function*/

/*TODO
	add definition for update_queues function*/

using namespace std;

class Library
{
private:
	vector<Employee> Employees;
	vector<Book> circBooks;
	vector<Book> archBooks;
public:
	bool pass_on(string title, Date curdate);
	void addBook(string bookName);
	void addEmployee(string Name);
	void circulateBook(string title, Date startDate);
	void update_queues(Employee*);
};
