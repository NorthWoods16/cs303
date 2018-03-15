#pragma once
#include"Date.h"
#include"Employee.h"
#include"Book.h"
#include <vector>

using namespace std;

class Library
{
private:
	vector<Employee> Employees;
	vector<Book> circBooks;
	vector<Book> archBooks;
	void pass_on(string title);
public:
	void addBook(string bookName);
	void addEmployee(string Name);
	void circulateBook(string title, Date startDate);
};