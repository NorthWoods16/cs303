#include "Priority_Pair.h"

struct Priority_Pair
{
	Priority_Pair()
	{
		priority = 0;
	}
	Priority_Pair(Employee *empa)
	{
		emp = empa;
		priority = 0;
	}
	Employee *emp;
	int priority;
	Employee *next;
};