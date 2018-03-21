#include "Priority_Queue.h"
#include <iostream>
using namespace std;

/*TODO
Run through code and make sure logic all works properly
add errors where errors should be added
clean up the code*/

//default constructor
Priority_Queue::Priority_Queue() : head(nullptr), size(0) {}


//inserts a priority_pair into the priority_queue based on the priority
void Priority_Queue::push(Employee *empa, int priority) {
	if (head == nullptr || priority > head->priority)
		head = new Priority_Pair(empa, priority, head);

	else {
		Priority_Pair* q = head;
		while (q->next != nullptr && q->next->priority >= priority)
			q = q->next;

		q->next = new Priority_Pair(empa, priority, q->next);
	}
	size++;
}


//Removes the priority pair from the head of the queue
void Priority_Queue::pop() {
	if (head == nullptr)
		throw invalid_argument("Queue is empty\n");

	Priority_Pair *tmp = head;
	// cout << "Deleted " << tmp->emp->name << "from queue\n";
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
	return size == 0;
}

//searches the queue for an Employee match and the priority
bool Priority_Queue::search(Employee *emp)
{
	Priority_Pair *ptr = head;
	while (ptr != nullptr)
	{
		if (ptr->emp == emp)
			return true;

		ptr = ptr->next;
	}
	return false;
}


//Finds the employee in the queue, removes them then reinserts them into the queue with the new priority
void Priority_Queue::update(Employee *emp, int priority)
{
	if (head == nullptr)
		throw invalid_argument("Queue is empty\n");

	// Catch case where the employee is at the head of the queue
	// Added as part of bug fix
	if (head->emp == emp) {
		pop();
		push(emp, priority);
	}

	else {
		Priority_Pair* ptr = head;
		while (ptr != nullptr && ptr->next->emp != emp)
			ptr = ptr->next;

		// Test if the item was found
		if (ptr != nullptr) {
			Priority_Pair* temp = ptr->next;
			ptr->next = temp->next;
			delete temp;

			// Update the priority then push back into queue
			push(emp, priority);
		}
		else {
			throw invalid_argument("Item is not in the queue\n");
		}
	}
}


//returns the employee at the front
Employee* Priority_Queue::get_front()
{
	return head->emp;
}
//returns the size of the queue
int Priority_Queue::getSize()
{
	return size;
}

Priority_Queue& Priority_Queue::operator=(const Priority_Queue& rhs) {
	while (head != nullptr)
		pop();

	Priority_Pair* ptr = rhs.head;
	while (ptr != nullptr) {
		push(ptr->emp, ptr->priority);
		ptr = ptr->next;
	}
	return *this;
}
