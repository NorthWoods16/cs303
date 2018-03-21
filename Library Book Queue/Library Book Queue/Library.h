#pragma once
#include"Date.h"
#include"Employee.h"
#include"Book.h"
#include <vector>


using namespace std;

class Library
{
private:
	//vector holds employee pointers
	vector<Employee*> Employees;
	//vector for books in circulation
	vector<Book> circBooks;
	//vector for arhcived books
	vector<Book> archBooks;
	//employee priority
	int getPriority(Employee*);
public:
	//passes book on to next employee of highest priority
	bool pass_on(string title, Date curdate);
	//adds a book
	void addBook(string bookName);
	//adds employee
	void addEmployee(string Name);
	//puts book into circulation
	void circulateBook(string title, Date startDate);
	//updates book queues
	void update_queues(Employee* e);
};
