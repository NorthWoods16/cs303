#pragma once
#include <string>

struct Employee
{
	Employee(std::string n) : name(n) {}
	std::string name;
	int waitingTime, retaintingTime;
};
