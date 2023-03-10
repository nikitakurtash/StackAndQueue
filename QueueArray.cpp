#include "QueueArray.h"

template<class T>
QueueArray<T>::QueueArray(int size) //конструктор
{
	if (size <= 0) throw WrongQueueArraySize(); //если размер меньше нуля, значит он указан неверно

	this->size = size;
	this->array = new T[size]; // создаем очередь с подаваемым размером
}
template QueueArray<int>::QueueArray(int size);
template QueueArray<char>::QueueArray(int size);

template<class T>
QueueArray<T>::~QueueArray() //деструктор
{
	delete this->array;
}
template QueueArray<int>::~QueueArray();
template QueueArray<char>::~QueueArray();

template<class T>
void QueueArray<T>::enQueue(const T& element) //вставка элемента
{
	if (this->index >= this->size) throw QueueArrayOverflow(); //если вершина очереди >= размера значит очередь заполнена

	this->array[this->index] = element; //вставляем элемент в вершину очереди

	this->index += 1; // индекс++
}
template void QueueArray<int>::enQueue(const int& element);
template void QueueArray<char>::enQueue(const char& element);

template<class T>
T QueueArray<T>::deQueue() //удаление элемента из очереди
{
	if (this->isEmpty()) throw QueueArrayUnderflow(); //если список пуст - значит исключительная ситуация

	this->index -= 1; //текущий размер очереди уменьшаем

	T output = this->array[0]; //достаем нижний элемент

	for (int i = 0; i < this->size; i++) {
		this->array[i] = this->array[i + 1]; //смешаем элементы
	}

	return output;//выводим нижний
}
template int QueueArray<int>::deQueue();
template char QueueArray<char>::deQueue();

template<class T>
bool QueueArray<T>::isEmpty()//пустая очередь
{
	return this->index == 0;
}
template bool QueueArray<int>::isEmpty();
template bool QueueArray<char>::isEmpty();