#pragma once
#include"Date.h"
#include <vector>

using namespace std;

class Library
{
private:
	void pass_on(string title);
public:
	void addBook(string bookName);
	void addEmployee(string Name);
	void circulateBook(string title, Date startDate);
};