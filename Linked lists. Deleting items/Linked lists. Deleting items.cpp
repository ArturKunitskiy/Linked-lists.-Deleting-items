#include "ForwardList.h"
#include <iostream>
using namespace std;

void ForwardList::push_back(int value)
{
	if (head && tail)
	{
		Node* new_node = new Node(value);
		tail->next = new_node;
		tail = new_node;
	}
	else
	{
		Node* new_node = new Node(value);
		head = new_node;
		tail = new_node;
	}
}

void ForwardList::push_front(int value)
{
	Node* new_node = new Node(value);
	new_node->next = head;
	head = new_node;
	if (!tail)
	{
		tail = new_node;
	}
}

void ForwardList::pop_front()
{
	if (head && tail)
	{
		Node* temp = head->next;
		delete head;
		if (!temp)
		{
			tail = temp;
		}
		head = temp;
	}
}

void ForwardList::pop_back()
{
	if (head && tail)
	{
		delete tail;
	}
}

bool ForwardList::push_after(Node* prev, int value)
{
	if (!prev)
	{
		return false;
	}
	Node* new_node = new Node(value);
	new_node->next = prev->next;
	prev->next = new_node;
	if (prev == tail)
	{
		tail = new_node;
	}
	return true;
}

void ForwardList::print()
{
	Node* current = head;
	while (current != nullptr)
	{
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

//дописала геттери для полей класу ForwardList для зберіганні їх інкапсульованими, але з можливістю за потреби їх дістати(приклад - строка 11 main.cpp)
Node* ForwardList::GetHead()
{
	return head;
}

Node* ForwardList::GetTail()
{
	return tail;
}

ForwardList::~ForwardList()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current->next;
		delete current;
		current = temp;
	}
	head = nullptr;
	tail = nullptr;
}
