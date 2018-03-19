#pragma once
#include"Date.h"
#include"Employee.h"
#include"Book.h"
#include <vector>

/*What has changed
	added definition for update_queues*/

/*TODO*/

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
	void update_queues(Employee* e);
};
