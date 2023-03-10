#pragma once
#include<exception>
#include<string>

class QueueArrayOverflow : public std::exception
{
private:
	const std::string reason;
public:
	QueueArrayOverflow();
	const char* what() const;
};

class QueueArrayUnderflow : public std::exception
{
private:
	const std::string reason;
public:
	QueueArrayUnderflow();
	const char* what() const;
};

class WrongQueueArraySize : public std::exception
{
private:
	const std::string reason;
public:
	WrongQueueArraySize();
	const char* what() const;
};