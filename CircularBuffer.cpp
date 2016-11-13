#include <iostream>
#include<cmath>
class CircularBuffer
{
public:

    CircularBuffer( int size )
    {
        head = tail = length = 0;
        bufferSize = size;
        arr = new int[bufferSize];
    }

    ~CircularBuffer()
    {
        delete[] arr;
    }

    // Добавить элемент
    void put( const int & value )
    {
        if ( tail == bufferSize )
        {
            tail = 0;
        }

        arr[tail] = value;
        ++tail;
        ++length;
    }


    // Извлечь последний элемент
    int & pop()
    {
        if ( head == bufferSize ) {
            head = 0;
        }
        int & elem = arr[head];
        ++head;
        --length;
        return elem;
    }
    int &  operator[](const int & j){
    int k =std::fmod(head+j)/size);
    int  &elem = arr[k];
    return k;}
    // Кол-во элементов в буфере
    size_t size() const
    {
        return length;
    }
    void printBuffer(){
    std::cout<<head<<tail }
    // Ёмкость буфера
    size_t capacity() const
    {
        return bufferSize;
    }


private:
    int * arr;             // массив-буфер
    int bufferSize;        // размер буфера
    int length;            // кол-во элементов в буффере
    int head;              // индекс первого элемента
    int tail;              // индекс последнего элемента
};


int main()
{
    CircularBuffer buf(3);

    for( int i = 0; i < 10; ++i )
    {
        buf.put( i * 2 );
        if ( buf.size() == buf.capacity() ) {
            std::cout << "---------------" << std::endl;
            while( buf.size() ) {
                std::cout << buf.pop() << std::endl;
            }
        }

    }

    std::cout << "---------------" << std::endl;
    while( buf.size() ) {
        std::cout << buf.pop() << std::endl;
    }
    return 0;
}
