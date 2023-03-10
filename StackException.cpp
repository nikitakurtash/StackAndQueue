#include "StackException.h"

StackArrayOverflow::StackArrayOverflow() : reason(" StackArrayOverflow") {}

const char* StackArrayOverflow::what() const
{
	return this->reason.c_str();
}

StackArrayUnderflow::StackArrayUnderflow() : reason(" StackArrayUnderflow") {}

const char* StackArrayUnderflow::what() const
{
	return this->reason.c_str();
}

WrongStackArraySize::WrongStackArraySize() : reason(" WrongStackArraySize") {}

const char* WrongStackArraySize::what() const
{
	return this->reason.c_str();
}