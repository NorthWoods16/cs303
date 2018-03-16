#include "Priority_Queue.h"
#include <iostream>
using namespace std;

int size;
Priority_Pair *head;

//default constructor
Priority_Queue::Priority_Queue()
{
	head->next = nullptr;
	size = 0;
}

//inserts a priority_pair into the priority_queue based on the priority
void Priority_Queue::insert(Employee *empa, int priority)
{
	Priority_Pair *tmp, *q;
	tmp = new Priority_Pair;
	tmp->emp = empa;
	tmp->priority = priority;
	if (head->emp == nullptr || priority > head->priority)
	{
		tmp->next = head;
		head = tmp;
		size++;
	}
	else
	{
		q = head;
		while (q->next != nullptr && q->next->priority >= priority)
			q = q->next;
		tmp->next = q->next;
		q->next = tmp;
		size++;
	}
}

//Removes the priority pair from the head of the queue
void Priority_Queue::pop()
{
	Priority_Pair *tmp;
	tmp = new Priority_Pair;
	if (head == nullptr)
		throw invalid_argument("Queue is empty\n");
	else
		tmp = head;
	cout << "Deleted " << tmp->emp->name << "from queue\n";
	head = head->next;
	delete tmp;
	size--;
}

//iterates through each pair in the queue and outputs their priority and Employee name
void Priority_Queue::display()
{
	Priority_Pair *ptr;
	ptr = new Priority_Pair;
	ptr = head;
	if (head == nullptr)
		throw invalid_argument("Queue is empty\n");
	else
	{
		cout << "Queue is :\n";
		cout << "Priority       Employee\n";
		while (ptr != nullptr)
		{
			cout << ptr->priority << "                 " << ptr->emp->name << endl;
			ptr = ptr->next;
		}
	}
}

//returns if queue is empty or not
bool Priority_Queue::isempty()
{
	if (size == 0)
		return true;
	else
		return false;
}

//searches the queue for an Employee match and the priority
bool Priority_Queue::search(Employee *emp)
{
	Priority_Pair *ptr;
	ptr = new Priority_Pair;
	if (head == nullptr)
		throw invalid_argument("Queue is empty\n");
	else
	{
		while (ptr != nullptr)
		{
			if (ptr->emp == emp)
				return true;
			ptr = ptr->next;
		}
		return false;
	}
}
//Finds the employee in the queue, removes them then reinserts them into the queue with the new priority
void Priority_Queue::update(Employee *emp, int priority)
{
	Priority_Pair *ptr;
	ptr = new Priority_Pair;
	if (head == nullptr)
		throw invalid_argument("Queue is empty\n");
	else
	{
		while (ptr->next->emp != emp)
		{
			ptr = ptr->next;
		}
		Priority_Pair* temp = ptr->next;
		ptr->next = temp->next;
		delete temp;
		insert(emp, priority);
		return;
	}
}

//returns the employee at the front
Employee* Priority_Queue::front()
{
	return head->emp;
}
//returns the size of the queue
int Priority_Queue::getSize()
{
	return size;
}
