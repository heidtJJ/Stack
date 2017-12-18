#ifndef _STACK_H_
#define _STACK_H_

#include<string>

// thrown when pop or top is used on empty stack
struct EmptyStackException
{
public:
	EmptyStackException() : EmptyStackException("") {};
	EmptyStackException(std::string message) : message_(message) {};
	const std::string& getMessage() const { return message_; };
private:
	std::string message_;
};


template<class T>
class Stack {
public:
	Stack();
	Stack(const T& newHeadData);
	void push(const T& newHeadData);
	void pop();
	inline const T& top() const;
	bool empty() const;
	const int& size() const;
	void listElements() const;// prints to std::cout the elements of the stack 
	
	template<class T>
	friend bool operator==(const Stack<T>& stack1, const Stack<T>& stack2);
	template<class T>
	friend bool operator!= (const Stack<T>& stack1, const Stack<T>& stack2);
	const Stack<T>& operator= (const Stack<T>& stack2);
	~Stack();
private:
	struct Node {
		T data;
		Node* nextNode;
	};
	void free();

	Node* head;
	int _size;

};

//////////////////////// OPERATORS ////////////////////////////
template<class T>
bool operator==(const Stack<T>& stack1, const Stack<T>& stack2){
	Stack<T>::Node* s1Ptr = stack1.head;
	Stack<T>::Node* s2Ptr = stack2.head;
	if (stack1._size != stack2._size) {
		return false;
	}
	else { // stacks are the same size
		for (int counter = 0; counter < stack1._size; counter++) {
			if (s1Ptr->data != s2Ptr->data) {
				return false;
			}
			s1Ptr = s1Ptr->nextNode;
			s2Ptr = s2Ptr->nextNode;
		}
		return true;
	}
}

template<class T>
inline bool operator!=(const Stack<T>& stack1, const Stack<T>& stack2){
	return (!(stack1==stack2));
}

template<class T>
const Stack<T>& Stack<T>::operator=(const Stack<T>& stack2) {
	free();
	Stack<T>::Node* currPtr = stack2.head;
	while (currPtr != nullptr) {
		currPtr = currPtr->nextNode;
	}
	return *this;
}

/////////////////////// CONSTRUCTORS //////////////////////////
template<class T>
Stack<T>::Stack() : _size(0), head(nullptr) {}

template<class T>
Stack<T>::Stack(const T& newHeadData) {
	_size = 1;
	head = new Node;
	head->data = newHeadData;
	head->nextNode = nullptr;
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
		throw EmptyStackException("Stack is empty. Cannot pop from the stack.");
	}
}
/////////////////////// ACCESSORS //////////////////////////
template<class T>
inline const T& Stack<T>::top() const {
	if (head != nullptr) return head->data;
	else throw EmptyStackException("Stack is empty. Cannot find top of the stack.");
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

/////////////////////// DESTRUCTOR //////////////////////////
template<class T>
void Stack<T>::free() {
	Node* currentNode = head;
	while (head != nullptr) {
		pop();
	}
}

template<class T>
Stack<T>::~Stack() {
	free();
}
#endif