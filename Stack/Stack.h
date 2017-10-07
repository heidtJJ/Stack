#pragma once
#include<string>
class EMPTYSTACKEXCEPTION
{
public:
	EMPTYSTACKEXCEPTION() : EMPTYSTACKEXCEPTION("") {};
	EMPTYSTACKEXCEPTION(std::string message) : message_(message) {};
	const std::string& getMessage() const { return message_; };
private:
	std::string message_;
};

struct Node {
	int data;
	Node* nextNode;
};

// Stack is a last-in-first-out data structure
class Stack {
public:
	Stack();
	Stack(const int& newHeadData);
	void push(const int& newHeadData);
	void pop();
	const int& top() const;
	bool empty() const;
	const int& size() const;
	void listElements()const;// prints to std::cout the elements of the stack 

private:
	Node* head;
	int _size;
};