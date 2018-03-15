#include "Priority_Queue.h"
#include <iostream>
using namespace std;



int size;
Priority_Pair *front;

Priority_Queue::Priority_Queue()
{
	front->next = nullptr;
	size = 0;
}
void Priority_Queue::insert(Employee *empa, int priority)
{
	Priority_Pair *tmp, *q;
	tmp->emp = empa;
	tmp->priority = priority;
	if (front->emp == nullptr || priority > front->priority)
	{
		tmp->next = front;
		front = tmp;
		size++;
	}
	else
	{
		q = front;
		while (q->next != nullptr && q->next->priority >= priority)
			q = q->next;
		tmp->next = q->next;
		q->next = tmp;
		size++;
	}
}

void Priority_Queue::pop()
{
	Priority_Pair *tmp;
	if (front == nullptr)
		cout << "Queue is empty\n";
	else
		tmp = front;
	cout << "Deleted " << tmp->emp->name << "from queue\n";
	front = front->next;
	delete tmp;
	size--;
}

void Priority_Queue::display()
{
	Priority_Pair *ptr;
	ptr = front;
	if (front == nullptr)
		cout << "Queue is empty\n";
	else
	{
		cout << "Queue is :\n";
		cout << "Priority       Item\n";
		while (ptr != nullptr)
		{
			cout << ptr->priority << "                 " << ptr->emp->name << endl;
			ptr = ptr->next;
		}
	}
}
bool Priority_Queue::isempty()
{
	if (size == 0)
		return true;
	else
		return false;
}