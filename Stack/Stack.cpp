#include "Stack.h"
#include<iostream>

Stack::Stack() {
	_size = 0;
	head = nullptr;
}

Stack::Stack(const int& newHeadData) {
	_size = 1;
	head = new Node;
	head->data = newHeadData;
}

void Stack::push(const int& newHeadData) {
	Node* newHead = new Node();
	newHead->data = newHeadData;
	newHead->nextNode = head;
	head = newHead;
	++_size;
}

void Stack::pop() {
	if (head != nullptr) {
		Node* nodeToDelete = head;
		head = head->nextNode;
		delete nodeToDelete;
		--_size;
	}
	else {
		std::cout << "Stack is empty. Cannot pop from the stack." << std::endl;
	}
}

const int& Stack::top() const {
	if (head != nullptr) {
		return head->data;
	}
	else {
		throw EMPTYSTACKEXCEPTION("Stack is empty.Cannot find top of the stack.");
	}
}

bool Stack::empty() const {
	return (_size == 0);
}

const int& Stack::size() const {
	return _size;
}

void Stack::listElements() const {
	Node* currentNode = head;
	std::cout << "Elements of stack: ";
	while (currentNode != nullptr)
	{
		std::cout << currentNode->data << " ";
		currentNode = currentNode->nextNode;
	}
	std::cout << "\n";
}