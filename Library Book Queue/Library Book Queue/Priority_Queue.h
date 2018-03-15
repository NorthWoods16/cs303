#pragma once
#include "Priority_Pair.h"

class Priority_Queue
{
private:
	int size;
	Priority_Pair *front;
public:
	Priority_Queue();
	void insert(Employee *empa, int priority);
	void pop();
	void display();
	bool isempty();
};