#pragma once
#include "Priority_Pair.h"

//Priority_Queue defintion. A Queue specific to a book with employees in order of priority. Highest priority at the head.
class Priority_Queue
{
private:
	int size;
	Priority_Pair *head;
public:
	Priority_Queue();
	void insert(Employee *empa, int priority);
	void pop();
	void display();
	bool isempty();
	bool search(Employee *emp);
	Employee* front();
	int getSize();
	void update(Employee *emp, int priority);
};