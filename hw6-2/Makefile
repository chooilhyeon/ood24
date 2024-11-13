#TODO: Set your googletest directory path
GTEST_DIR = /Users/chu-ilhyeon/ood24/googletest-main/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS = -fsanitize=address --std=c++17 -g

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

#TODO: Set your executable target
all : hw6
	clang++ -fsanitize=address --std=c++17  hw6.cc -o hw6
#TODO: Change 'hw6.cc' and 'int_node.o' to your main source file and util target respectively
hw6: hw6.cc int_node.o string_node.o tree_util.o
	$(CC) $(CXXFLAGS) $^ -o $@

#TODO: Change 'int_node.h' and 'int_node.cc' to your source files
int_node.o : int_node.cc
	$(CC) $(CXXFLAGS) -c $^ -o $@

string_node.o : string_node.cc
	$(CC) $(CXXFLAGS) -c $^ -o $@

tree_util.o : tree_util.cc
	$(CC) $(CXXFLAGS) -c $^ -o $@

#TODO: Change 'util_test.cc' to your test file
test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

#TODO: Change 'util_test.o'and 'int_node.o' to your object targets
test: test.o int_node.o string_node.o tree_util.o node.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

#TODO: Change 'main' and 'main_test' to your executable and test respectively
clean:
	 rm -f gtest.a gtest_main.a *.o hw6 test

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
	cpplint --filter=-legal/copyright,-build/header_guard,-build/include_subdir,-build/include_order,-runtime/string *.cc *.h

.PHONY: all clean lint
