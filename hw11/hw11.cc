#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <string>
#include "sort.h"




int main() {
printf("테스트");
std::list<int> list = {1, 3, 5, 2, 6, 7, 4, 0};
std::list<char> list2 = {'a', 'c', 'e', 'b', 'f', 'g', 'd', 'z'};
std::list<std::string> list3 = {"vector", "list", "queue", "stack"};
std::list<std::string> list4 = {"abcd", "acbd", "ba", "ac"};


SortAndPrint(&list, IncreasingOrder<int>());

SortAndPrint(&list, DecreasingOrder<int>());

SortAndPrint(&list2, IncreasingOrder<char>());

SortAndPrint(&list2, DecreasingOrder<char>());

SortAndPrint(&list3, IncreasingOrder<std::string>());
SortAndPrint(&list4, IncreasingOrder<std::string>());
return 0;
}
