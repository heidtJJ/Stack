#ifndef _EMPTY_STACK_EXCEPTION_
#define _EMPTY_STACK_EXCEPTION_
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

#endif
