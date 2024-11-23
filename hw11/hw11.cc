#include <iostream>
#include <cstdio>
#include <vector>
#include "sort.h"


template <typename T, typename N>
void SortAndPrint(T* container) {
	for (int n : *container) {
		std::cout << n << ' ';
	}
	std::cout << "-> ";

	Sort<T, N>(container->begin(), container->end());

	for(int n : *container) {
		std::cout << n << ' ';
	}
	std::cout << std::endl;
}

class IntIncreasingOrder{
	public:
    IntIncreasingOrder() {}
	int operator()(const int& x, const int& y) {
		if(x > y) {
			return 1;
		} else {
			return 0;
		}
	}
};

class IntDecreasingOrder{
	public:
	int operator()(const int& x, const int& y) {
		if(x < y) {
			return 1;
		} else {
			return 0;
		}
	}
};



int main() {
printf("테스트");
std::vector<int> vec = {1, 3, 5, 2, 6, 7, 4, 0};

SortAndPrint<std::vector<int>, IntIncreasingOrder>(&vec);

return 0;
}
