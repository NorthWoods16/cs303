#pragma once
#include "Priority_Pair.h"

/*what did
	changed insert to push*/

class Priority_Queue
{
private:
	int size;
	Priority_Pair *front;
public:
	Priority_Queue();
	void push(Employee *empa, int priority);
	void pop();
	void display();
	bool isempty();
	bool Priority_Queue::search(Employee *emp);
	void Priority_Queue::update(Employee *emp, int priority);
	Employee* Priority_Queue::front();
	int getSize();
};
