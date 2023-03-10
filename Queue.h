#pragma once

#include <iostream>

using namespace std;

template<class T>
class Queue {
public:
	virtual ~Queue() {};
	virtual void enQueue(const T& element) = 0; // ���������� �������� � �������
	virtual T deQueue() = 0; // �������� �������� �� �������
	virtual bool isEmpty() = 0; // �������� ������� �� ������� 
};