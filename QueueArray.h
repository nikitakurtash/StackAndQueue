#pragma once

#include "Queue.h"
#include "QueueException.h"

template<class T>
class QueueArray : public Queue<T>
{
private:
	int size = 0;
	int index = 0;
	T* array;
public:
	QueueArray(int size); 
	~QueueArray();

	void enQueue(const T& element); //���������� � �������
	T deQueue(); //�������� �� �������
	bool isEmpty(); //�������
};
