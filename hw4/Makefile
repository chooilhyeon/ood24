#TODO: Set your googletest directory path
GTEST_DIR = /Users/chu-ilhyeon/ood24/googletest-main/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

#TODO: Set your executable target
all : hw4
	clang++ --std=c++17  hw4.cc -o hw4
#TODO: Change 'hw4.cc' and 'int_set.o' to your main source file and util target respectively
hw4: hw4.cc int_set.o 
	$(CC) --std=c++17 $^ -o $@

#TODO: Change 'int_set.h' and 'int_set.cc' to your source files
int_set.o : int_set.cc
	$(CC) --std=c++17 -c $^ -o $@

#TODO: Change 'util_test.cc' to your test file
test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO: Change 'util_test.o'and 'int_set.o' to your object targets
test: test.o int_set.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

#TODO: Change 'main' and 'main_test' to your executable and test respectively
clean:
	 rm -f gtest.a gtest_main.a *.o hw4 test

gtest-all.o: $(GTEST_SRCS_) 
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) --std=c++17 -c\
		$(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^


lint:
	cpplint --filter=-legal/copyright,-build/header_guard,-build/include_subdir,-build/include_order *.cc *.h

.PHONY: all clean lint
