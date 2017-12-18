#include "Interface.h"
#include<iostream>

inline void Interface::pushValToStack() {
	std::string userValue = "";
	std::cout << "Give an entry to add to the stack: ";
	std::cin >> userValue;
	buffer.push(userValue);
}

void Interface::listOptions() {
	std::cout << "Enter one number to choose one of the following options:\n";
	std::cout << "1: Push value to stack.\n";
	std::cout << "2: Pop value from stack.\n";
	std::cout << "3: Show top value of stack.\n";
	std::cout << "4: Show size of stack.\n";
	std::cout << "5: Show if stack is empty.\n";
	std::cout << "6: List elements of stack.\n";
	std::cout << "Any other number: End program.\n";
}

const int Interface::getUserChoice() {
	int userChoice = -1;
	listOptions();
	while (!(std::cin >> userChoice))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //disregard input
		std::cout << "INVALID INPUT - please re-enter choice.\n";
	}
	return userChoice;
}

void Interface::performOperation(const int& userChoice) {
	system("CLS");
	switch (userChoice) {
	case 1: pushValToStack();
		break;
	case 2:	try { buffer.pop(); }
			catch (EmptyStackException ese) { std::cout << ese.getMessage() << std::endl; }
			break;
	case 3:	try { std::cout << "Top value of stack: " << buffer.top() << std::endl; }
			catch (EmptyStackException ese) { std::cout << ese.getMessage() << std::endl; }
			break;
	case 4:	std::cout << "Size of stack: " << buffer.size() << std::endl;
		break;
	case 5:	std::cout << "Stack is " << ((buffer.empty() == true) ? "" : "not ") << "empty." << std::endl;
		break;
	case 6:	buffer.listElements();
		break;
	default: quitProgram = true;
		break;
	}
}


void Interface::run() {
	int userChoice;
	while (!quitProgram) {
		userChoice = getUserChoice();
		std::cout << "\n";
		performOperation(userChoice);
		std::cout << "\n";
	}
}