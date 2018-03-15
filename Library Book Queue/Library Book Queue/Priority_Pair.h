#pragma once
#include "Employee.h"
struct Priority_Pair
{
	int priority;
	Employee *emp;
	Priority_Pair *next;
	Priority_Pair();
	Priority_Pair(Employee *emp);
};