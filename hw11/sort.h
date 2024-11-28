#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <vector>
#include <string>


template <typename T, typename N>
void Sort(typename T::iterator begin, typename T::iterator end, N compare) {
	if(begin == end) {
		return;
	}
	for (typename T::iterator i = begin; i != end; i++) {
		for (typename T::iterator j = i; j != end; j++) {
			if(compare(*i, *j)) {
				std::swap(*i, *j);
			}
		}
	}
}

template <typename T, typename N>
std::string SortAndPrint(T* container, N compare) {
	std::string result;
	for (auto n : *container) {
		std::cout << n << ' ';
		result += n + ' ';
	}
	std::cout << "-> ";
	result += "-> ";

	Sort<T, N>(container->begin(), container->end(), compare);

	for(auto n : *container) {
		std::cout << n << ' ';
		result += n + ' ';
	}
	std::cout << std::endl;
	return result;
}

template <typename T>
class IncreasingOrder{
	public:
	bool operator()(const T& x, const T& y) {
		return x > y;
	}
};

template <typename T>
class DecreasingOrder{
	public:
	bool operator()(const T& x, const T& y) {
		return x < y;
	}
};

#endif  //  _SORT_H_
