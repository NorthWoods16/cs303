#include "Priority_Pair.h"

//default constructor
Priority_Pair::Priority_Pair() : priority(0), next(nullptr) {}

//overloaded constructor
Priority_Pair::Priority_Pair(Employee *empa, int priorityA, Priority_Pair* n) :
									emp(empa), priority(priorityA), next(n) {}

