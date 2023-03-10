#include <iostream>
#include "StackArray.h"
#include "QueueArray.h"

int randomInteger(int max);
void testStackArray();
void testStackArrayOverflow();
void testStackArrayUnderflow();
void testWrongStackArraySize();
void testQueueArray();
void testQueueArrayOverflow();
void testQueueArrayUnderflow();
void testWrongQueueArraySize();
bool isLeftBracket(char value);
bool isRightBracket(char value);
template<typename T>
bool checkBalanceBrackets(const T& text, const int maxDeep);

int main()
{
    if (checkBalanceBrackets("a(b[c]d)e", 3)) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}

int randomInteger(int max) { //вспомогательная функция для получения псевдорандомного числа
    return (float)rand() / RAND_MAX * max;
}

void testStackArray() //Тестирование ограниченного стека
{
    int size = 16; 

    StackArray<int> stack(size); // создаем стек с указанным размером

    cout << "Pushing: ";
    for (int i = 0; i < size; i++) {
        int j = randomInteger(100); //j - случайное целое число до 100

        cout << j << " "; //выводим элемент

        stack.push(j); //добавляем элемент в стек
    }
    cout << endl;

    cout << "Popping: ";
    for (int i = 0; i < size; i++) { 
        cout << stack.pop() << " "; //достаем элемент/печатаем/удаляем
    }
    cout << endl;
}

void testStackArrayOverflow() //тест переполнения 
{
    int size = 16;

    StackArray<int> stack(size);

    cout << "Testing overflow..." << endl;
    for (int i = 0; i < size + 2; i++) {
        int j = randomInteger(100); //добавляем элементов больше чем размер стека

        cout << "Pushing index: " << i << " value: " << j;

        try {
            stack.push(j); //элемент добавлен - успех
            cout << " Success" << endl;
        }
        catch (StackArrayOverflow& e) { //список полон - исключение
            std::cerr << e.what()<<endl;
        }
    }
    cout << endl;
}

void testStackArrayUnderflow() //тест пустоты
{
    int size = 16;

    StackArray<int> stack(size);

    cout << "Pushing: ";
    for (int i = 0; i < size; i++) {
        int j = randomInteger(100);

        cout << j << " ";

        stack.push(j); //вставляем элементы
    }
    cout << endl;

    cout << "Testing underflow..." << endl;
    for (int i = 0; i < size + 2; i++) {//удаляем на два элемента больше чем есть
        int j = randomInteger(100);

        cout << "Popping index: " << i; // счетчик значений

        try {
            cout << " value: " << stack.pop(); //удаляем и выводим последний элемент массива
            cout << " Success" << endl;
        }
        catch (StackArrayUnderflow& e) { //если стек пуст, а мы продолжаем удалять элементы - исключение
            std::cerr << e.what() << endl;
        }
    }
    cout << endl;
}

void testWrongStackArraySize() //проверка исключения на размер стека
{
    for (int i = -1; i < 2; i++) {
        try {
            cout << "Setting size: " << i;
            StackArray<int> stack(i); //создаем стек с размером i
            cout << " Success" << endl;
        }
        catch (WrongStackArraySize& e) { //если размер <= 0, то вызываем исключение
            std::cerr << e.what() << endl;
        }
    }
}

void testQueueArray() //тестирование ограниченной очереди
{
    int size = 16; 

    QueueArray<int> queue(size); //создаем очередь с заданным размером

    cout << "enQueue: ";
    for (int i = 0; i < size; i++) {
        int j = randomInteger(100); 

        cout << j << " ";

        queue.enQueue(j); //добавляем элементы в очередь
    }
    cout << endl;

    cout << "deQueue: ";
    for (int i = 0; i < size; i++) {
        cout << queue.deQueue() << " "; // вынимаем/печатаем/сдвигаем элементы
    }
    cout << endl;
}

void testQueueArrayOverflow() // тест переполнения очереди
{
    int size = 16;

    QueueArray<int> queue(size);

    cout << "Testing overflow..." << endl;
    for (int i = 0; i < size + 2; i++) {
        int j = randomInteger(100); 
        //пытаемся добавить в очередь на два элемента больше размера
        cout << "enQueue index: " << i << " value: " << j;

        try {
            queue.enQueue(j);
            cout << " Success" << endl; //элемент добавлен - успех
        }
        catch (QueueArrayOverflow& e) { // места нет - вызываем исключение
            std::cerr << e.what() << endl;
        }
    }
    cout << endl;
}

void testQueueArrayUnderflow() //проверка массива на пустоту 
{
    int size = 16;

    QueueArray<int> queue(size);

    cout << "enQueue: ";
    for (int i = 0; i < size; i++) {
        int j = randomInteger(100);

        cout << j << " ";

        queue.enQueue(j); //вставляем элементы в очередь
    }
    cout << endl;

    cout << "Testing underflow..." << endl;
    for (int i = 0; i < size + 2; i++) {
        int j = randomInteger(100);

        cout << "deQueue index: " << i;
        // достаем из очереди на два элемента больше чем ее размер
        try {
            cout << " value: " << queue.deQueue();
            cout << " Success" << endl;
        }
        catch (QueueArrayUnderflow& e) { //получаем исключение
            std::cerr << e.what() << endl;
        }
    }
    cout << endl;
}

void testWrongQueueArraySize() // проверка правильности очереди
{
    for (int i = -1; i < 2; i++) {
        try {
            cout << "Setting size: " << i;
            QueueArray<int> queue(i); //создаем очередь с размером i
            cout << " Success" << endl; 
        }
        catch (WrongQueueArraySize& e) { //если размер <= 0, то вызываем исключение
            std::cerr << e.what() << endl;
        }
    }
}

bool isLeftBracket(char value) //левая скобка - true
{
    return value == '(' || value == '{' || value == '[';
}

bool isRightBracket(char value) // правая скобка - true
{
    return value == ')' || value == '}' || value == ']';
}

template<typename T>
bool checkBalanceBrackets(const T& text, const int maxDeep) //проверка правильности расстановки скобок
{
    StackArray<char> stack(maxDeep); //создаем стек с размерностью равной максимальной глубине скобок

    int index = 0;

    while (true) {
        char current = text[index]; 

        if (current) {
            cout << current << endl;
            if (isLeftBracket(current)) { //если текущее значение - левая скобка
                try {
                    stack.push(current); //вводим левую скобку в стек
                }
                catch (StackArrayOverflow) { //если левых скобок больше максимальной вложенности - false
                    return false;
                }
            }
            if (isRightBracket(current)) { //если текущее значение - правая скобка
                if (stack.isEmpty()) return false; //если левые скобки закончились (стек пуст), а правые скобки еще остались - false

                char should = stack.pop(); //записываем в переменную значение удаляемой скобки

                cout << current << should << endl; //выводим текущее и удаленное значение

                if (
                    (current != ')' || should != '(') &&
                    (current != '}' || should != '{') &&
                    (current != ']' || should != '[')
                    ) return false; //если скобки разные 
            }
        }
        else break;

        index += 1; //переходим к следующей скобке
    }

    return stack.isEmpty();//возвращаем true, если в конце списка скобок стек остается пустым 
}
