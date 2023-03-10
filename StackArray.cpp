#include "StackArray.h"

template<class T>
StackArray<T>::StackArray(int size) //�����������
{
	if (size <= 0) throw WrongStackArraySize(); //�������� �� ������ �������� �������
	//�������� ����� � �������� size
	this->size = size;
	this->array = new T[this->size];
}
template StackArray<int>::StackArray(int size);
template StackArray<char>::StackArray(int size);

template<class T>
StackArray<T>::~StackArray() //����������
{
	delete this->array;
}
template StackArray<int>::~StackArray();
template StackArray<char>::~StackArray();

template<class T>
void StackArray<T>::push(const T& element) //�������
{
	if (this->index >= this->size) throw StackArrayOverflow();//���� ������� ������� >= ������� - ������

	this->array[this->index] = element; // ������� ������� ����� = ������������ �������� 

	this->index += 1; // �������� ����
}
template void StackArray<int>::push(const int& element);
template void StackArray<char>::push(const char& element);

template<class T>
T StackArray<T>::pop()
{
	if (this->isEmpty()) throw StackArrayUnderflow(); // ���� ���� ������ - ���������� 

	this->index -= 1; //��������� ������ 

	return this->array[this->index];//���������� ������� �������
}
template int StackArray<int>::pop();
template char StackArray<char>::pop();

template<class T>
bool StackArray<T>::isEmpty() // ������ ���� ������ �������� = 0
{
	return this->index == 0; 
}
template bool StackArray<int>::isEmpty();
template bool StackArray<char>::isEmpty();