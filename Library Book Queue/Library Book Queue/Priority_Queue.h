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
	bool search(Employee *emp);
	void update(Employee *emp, int priority);
	Employee* front();
	int getSize();
};
