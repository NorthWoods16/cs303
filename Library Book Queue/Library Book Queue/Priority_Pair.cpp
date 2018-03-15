#include "Priority_Pair.h"

struct Priority_Pair
{
	Priority_Pair(Employee *empa)
	{
		emp = empa;
	}
	Employee *emp;
	int priority;
	Employee *next;
};