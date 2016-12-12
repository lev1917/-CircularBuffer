#include<iostream>
#include<conio.h>
#include<cmath>
#include<vector>
#include<string>
template<typename T,int size>
class CircularBuffer{ 
	public:
	   CircularBuffer(){
		   arr = std::vector<T>(size);
		tail = 0;
		head = 0;
	  }
	   void add(T& value) {
		   if (tail == arr.size()) {
			   arr.push_back(value);
			   tail++;
			   return;
		   }
		   arr[tail] = value;
		   tail++;

	 }
	   T  operator[](int i) {
		   if (i <= 0) {
			   T  cur= (arr[tail - 1]);
			   return cur;
		   }
		   int k = std::fmod(i, tail-head);
		   T  cur = arr[k];
		   return cur;
			   }
	   T  pop(){
		   if (head == arr.size()) {
			   head = 0;
		   }
			   T  cur = arr[head];
			   head++;
			   return cur;
		   }
	   void print() {
		   std::cout << "Begin" << std::endl;
		   for (int i = 0; i < (tail - head); i++) {
			   std::cout << i << " : " << (*this)[i] << std::endl;
		   }
		   std::cout << "End"<<std::endl;

	   }
	private:
		int head, tail;
		std::vector<T>arr;

};
int main() {
	CircularBuffer<int, 10>my;
	int x = 5;
	int y = 7;
	my.print();
	my.add(x);
	my.add(y);
	std::cout << my[0] << std::endl;
	std::cout << my.pop() << std::endl;
		

	my.print();
	_getch();
	return 0;
	
}
