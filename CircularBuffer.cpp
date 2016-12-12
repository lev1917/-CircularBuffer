#include<iostream>
#include<conio.h>
#include<cmath>
#include<vector>
#include<string>
template<typename T>
class CircularBuffer
{
public:

	CircularBuffer(int size)
	{
		head = tail = length = 0;
		bufferSize = size;
		arr = new T[bufferSize];
	}

	~CircularBuffer()
	{
		delete[] arr;
	}

	// Добавить элемент
	void put(const T & value)
	{
		if (tail == bufferSize)
		{
			tail = 0;
		}

		arr[tail] = value;
		++tail;
		++length;
	}


	// Извлечь последний элемент
	T & pop()
	{
		if (head == bufferSize) {
			head = 0;
		}
		T & elem = arr[head];
		++head;
		--length;
		return elem;
	}
	T &  operator[](const int & j) {
		
		int k = std::fmod(head + j,length);
		T  & elem = arr[k];
		return k;
	}
	// Кол-во элементов в буфере
	size_t size() const
	{
		return length;
	}
	void printBuffer() {
		std::string L = std::to_string(head);
		L += ",";
		L += std::to_string(tail);
		L += ",";
		for (int i = 0; i<length; i++) {
			L += std::to_string((*this)[i]);
			L += ",";
		}
		for (int j=0; j < L.size(); j++) {
			std::cout << L[j];
		}
	}
	// Ёмкость буфера
	size_t capacity() const
	{
		return bufferSize;
	}


private:
	T * arr;             // массив-буфер
	int bufferSize;        // размер буфера
	int length;            // кол-во элементов в буффере
	int head;              // индекс первого элемента
	int tail;              // индекс последнего элемента
};




int main()
{
	CircularBuffer<int> buf(3);

	for (int i = 0; i < 10; ++i)
	{
		buf.put(i * 2);
		buf.printBuffer();
		if (buf.size() == buf.capacity()) {
			std::cout << "---------------" << std::endl;
			while (buf.size()) {
				std::cout << buf.pop() << std::endl;
			}
		}

	}

	std::cout << "---------------" << std::endl;
	while (buf.size()) {
		std::cout << buf.pop() << std::endl;
	}

	_getch();
	return 0;
}

