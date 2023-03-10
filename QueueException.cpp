#include "QueueException.h"

QueueArrayOverflow::QueueArrayOverflow() : reason(" QueueArrayOverflow") {}

const char* QueueArrayOverflow::what() const
{
	return this->reason.c_str();
}

QueueArrayUnderflow::QueueArrayUnderflow() : reason(" QueueArrayUnderflow") {}

const char* QueueArrayUnderflow::what() const
{
	return this->reason.c_str();
}

WrongQueueArraySize::WrongQueueArraySize() : reason(" WrongQueueArraySize") {}

const char* WrongQueueArraySize::what() const
{
	return this->reason.c_str();
}