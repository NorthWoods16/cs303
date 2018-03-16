#pragma once
#include "Employee.h"

//Priority_Pair declaration. Holds an Employee, their priority, and a link to the next priority_pair in the list.
struct Priority_Pair
{
	int priority;
	Employee *emp;
	Priority_Pair *next;
	Priority_Pair();
	Priority_Pair(Employee *emp, int priority);
};
