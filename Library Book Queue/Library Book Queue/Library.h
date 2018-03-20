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
	//vector holds employees that will check out books
	vector<Employee> Employees;
	//vector holds books that are circulation
	vector<Book> circBooks;
	//vector holds archived books
	vector<Book> archBooks;
public:
	//locates a book in circulating book vector and calls the book method "passon"
	bool pass_on(string title, Date curdate);
	//adds a book object to the archived books vector
	void addBook(string bookName);
	//adds an employee to the employee vector 
	void addEmployee(string Name);
	//book is moved from archived book vector into circulating book vector
	void circulateBook(string title, Date startDate);
	//updates book queues
	void update_queues(Employee* e);
};
