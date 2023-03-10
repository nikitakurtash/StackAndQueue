#include "QueueArray.h"

template<class T>
QueueArray<T>::QueueArray(int size) //�����������
{
	if (size <= 0) throw WrongQueueArraySize(); //���� ������ ������ ����, ������ �� ������ �������

	this->size = size;
	this->array = new T[size]; // ������� ������� � ���������� ��������
}
template QueueArray<int>::QueueArray(int size);
template QueueArray<char>::QueueArray(int size);

template<class T>
QueueArray<T>::~QueueArray() //����������
{
	delete this->array;
}
template QueueArray<int>::~QueueArray();
template QueueArray<char>::~QueueArray();

template<class T>
void QueueArray<T>::enQueue(const T& element) //������� ��������
{
	if (this->index >= this->size) throw QueueArrayOverflow(); //���� ������� ������� >= ������� ������ ������� ���������

	this->array[this->index] = element; //��������� ������� � ������� �������

	this->index += 1; // ������++
}
template void QueueArray<int>::enQueue(const int& element);
template void QueueArray<char>::enQueue(const char& element);

template<class T>
T QueueArray<T>::deQueue() //�������� �������� �� �������
{
	if (this->isEmpty()) throw QueueArrayUnderflow(); //���� ������ ���� - ������ �������������� ��������

	this->index -= 1; //������� ������ ������� ���������

	T output = this->array[0]; //������� ������ �������

	for (int i = 0; i < this->size; i++) {
		this->array[i] = this->array[i + 1]; //������� ��������
	}

	return output;//������� ������
}
template int QueueArray<int>::deQueue();
template char QueueArray<char>::deQueue();

template<class T>
bool QueueArray<T>::isEmpty()//������ �������
{
	return this->index == 0;
}
template bool QueueArray<int>::isEmpty();
template bool QueueArray<char>::isEmpty();