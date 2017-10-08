#ifndef _STACK_H_
#define _STACK_H_
#include"EmptyStackException.h"

// Stack is a last-in-first-out data structure
template<class T>
class Stack {
public:
	Stack();
	Stack(const T& newHeadData);
	void push(const T& newHeadData);
	void pop();
	const T& top() const;
	bool empty() const;
	const int& size() const;
	void listElements()const;// prints to std::cout the elements of the stack 

private:

	struct Node {
		T data;
		Node* nextNode;
	};

	Node* head;
	int _size;
};

/////////////////////// CONSTRUCTORS //////////////////////////
template<class T>
Stack<T>::Stack() : _size(0), head(nullptr) {}

template<class T>
Stack<T>::Stack(const T& newHeadData) {
	_size = 1;
	head = new Node;
	head->data = newHeadData;
}

/////////////////////// MUTATORS //////////////////////////
template<class T>
void Stack<T>::push(const T& newHeadData) {
	Node* newHead = new Node();
	newHead->data = newHeadData;
	newHead->nextNode = head;
	head = newHead;
	++_size;
}

template<class T>
void Stack<T>::pop() {
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
/////////////////////// ACCESSORS //////////////////////////
template<class T>
const T& Stack<T>::top() const {
	if (head != nullptr) {
		return head->data;
	}
	else {
		throw EMPTYSTACKEXCEPTION("Stack is empty.Cannot find top of the stack.");
	}
}

template<class T>
bool Stack<T>::empty() const {
	return (_size == 0);
}

template<class T>
const int& Stack<T>::size() const {
	return _size;
}

template<class T>
void Stack<T>::listElements() const {
	Node* currentNode = head;
	std::cout << "Elements of stack: ";
	while (currentNode != nullptr)
	{
		std::cout << currentNode->data << " ";
		currentNode = currentNode->nextNode;
	}
	std::cout << "\n";
}
#endif