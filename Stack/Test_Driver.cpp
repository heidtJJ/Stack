#include<iostream>
#include"Stack.h"

void pushValToStack(Stack& userStack) {
	int userValue = -1;
	std::cout << "Enter a value to add to the stack: ";
	std::cin >> userValue;
	userStack.push(userValue);
}

const int listOptions() {
	int userChoice = -1;
	std::cout << "Enter one number to choose one of the following options:\n";
	std::cout << "1: Push value to stack.\n2: Pop value from stack.\n";
	std::cout << "3: Show top value of stack.\n4: Show size of stack.\n";
	std::cout << "5: Show if stack is empty.\n6: List elements of stack.\n";
	std::cout << "Anything else: End program.\n";
	while (!(std::cin >> userChoice))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //disregard input
		std::cout << "INVALID INPUT - please re-enter choice.\n";
	}
	return userChoice;
}

void performOperation(const int& userChoice, Stack& stack, bool& quitProgram) {
	system("CLS");
	switch (userChoice) {
	case 1: pushValToStack(stack);
		break;
	case 2:	stack.pop();
		break;
	case 3:	try { std::cout << "Top value of stack: " << stack.top() << std::endl; }
			catch (EMPTYSTACKEXCEPTION ese) { std::cout << ese.getMessage() << std::endl; }
		break;
	case 4:	std::cout << "Size of stack: " << stack.size() << std::endl;
		break;
	case 5:	std::cout << "Stack is " << ((stack.empty() == true) ? "" : "not ") << "empty." << std::endl;
		break;
	case 6:	stack.listElements();
		break;
	default: quitProgram = true;
		break;
	}
}

int main() {
	Stack myStack;
	bool quitProgram = false;
	int userChoice = -1;
	while (!quitProgram) {
		userChoice = listOptions();
		std::cout << "\n";
		performOperation(userChoice, myStack, quitProgram);
		std::cout << "\n";
	}


	return 0;
}