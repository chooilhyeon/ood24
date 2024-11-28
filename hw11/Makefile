#TODO: Set your googletest directory path
GTEST_DIR = /Users/chu-ilhyeon/ood24/googletest-main/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all : hw11

hw11: hw11.cc sort.o #vector.o list.o stack.o queue.o
	$(CC) --std=c++17 $^ -o $@

vector.o : vector.cc
	$(CC) --std=c++17 -c $< -o $@

list.o : list.cc
	$(CC) --std=c++17 -c $< -o $@

stack.o : stack.cc
	$(CC) --std=c++17 -c $< -o $@

queue.o : queue.cc
	$(CC) --std=c++17 -c $< -o $@

sort.o : sort.cc
	$(CC) --std=c++17 -c $< -o $@

test.o : test.cc $(GTEST_HEADERS)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 -c $< -o $@

test: test.o sort.o gtest_main.a #vector.o list.o stack.o queue.o gtest_main.a
	$(CC) $(CPPFLAGS) $(CXXFLAGS) --std=c++17 $^ -o $@

clean:
	rm -f gtest.a gtest_main.a *.o hw11 test

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


