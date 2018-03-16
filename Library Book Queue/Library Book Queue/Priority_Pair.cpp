#include "Priority_Pair.h"

//default constructor
Priority_Pair::Priority_Pair()
{
	priority = 0;
}
//overloaded constructor
Priority_Pair::Priority_Pair(Employee *empa, int priorityA)
{
	emp = empa;
	priority = priorityA;
}