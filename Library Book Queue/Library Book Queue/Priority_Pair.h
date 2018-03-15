#pragma once
#include "Employee.h"
struct Priority_Pair
{
	Priority_Pair();
	Priority_Pair(Employee *emp);
	int priority;
	Employee *emp;
	Employee *next;
};