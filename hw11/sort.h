#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <vector>


template <typename T, typename N>
void Sort(typename T::iterator begin, typename T::iterator end) {
	if(begin == end) {
		return;
	}
	if(N(begin, ++begin)) {
		std::swap(begin, --begin);
	}
	Sort<T, N>(++begin, end);
}

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

#endif  //  _SORT_H_
