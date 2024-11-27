#include <iostream>
#include <cstdio>
#include <vector>
#include "sort.h"




int main() {
printf("테스트");
std::vector<int> vec = {1, 3, 5, 2, 6, 7, 4, 0};

SortAndPrint<std::vector<int>, IntIncreasingOrder>(&vec);

return 0;
}
