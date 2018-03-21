#pragma once
#include "Priority_Pair.h"

/*Class declaration for Priority Queue with queue functions, getters and size and head member variables*/

class Priority_Queue
{
private:
	int size;
	Priority_Pair *head;
public:
	Priority_Queue();
	void push(Employee *empa, int priority);
	void pop();
	void display();
	bool isempty();
	bool search(Employee *emp);
	void update(Employee *emp, int priority);
	Employee* get_front();
	Priority_Queue& operator= (const Priority_Queue&);
	int getSize();
};
