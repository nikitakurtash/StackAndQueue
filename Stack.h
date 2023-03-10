#pragma once

#include <iostream>

using namespace std;

template<class T>
class Stack {
public:
	virtual ~Stack() {}; // ����������
	virtual void push(const T& element) = 0; //���������� ��������� � ����
	virtual T pop() = 0;// �������� � ����������� �������� ��������. 
	virtual bool isEmpty() = 0;// �������� ����� �� �������
};