#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <string>
#include "Stack.h"

class Interface {
public:
	void run();

private:
	void performOperation(const int& userChoice);
	const int getUserChoice();
	void pushValToStack();
	void listOptions();

	Stack<std::string> buffer;
	bool quitProgram = false;
};

#endif _INTERFACE_H_