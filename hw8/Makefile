# TODO: Set your googletest directory path
GTEST_DIR = /Users/chu-ilhyeon/ood24/googletest-main/googletest

CC=clang++
CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS = --std=c++17 -g

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

OBJS = car.o car_builder.o door.o hyundai_parts_factory.o kia_parts_factory.o roof.o wheel.o part.o

# hw8 executable
hw8: hw8.o $(OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) hw8.o $(OBJS) -o hw8

# test executable
test: test.o $(OBJS) gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) test.o $(OBJS) gtest_main.a -o test

part.o: part.cc part.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c part.cc -o part.o

car.o: car.cc car.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c car.cc -o car.o

car_builder.o: car_builder.cc car_builder.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c car_builder.cc -o car_builder.o

door.o: door.cc door.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c door.cc -o door.o

hyundai_parts_factory.o: hyundai_parts_factory.cc hyundai_parts_factory.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c hyundai_parts_factory.cc -o hyundai_parts_factory.o

kia_parts_factory.o: kia_parts_factory.cc kia_parts_factory.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c kia_parts_factory.cc -o kia_parts_factory.o

roof.o: roof.cc roof.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c roof.cc -o roof.o

wheel.o: wheel.cc wheel.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c wheel.cc -o wheel.o

hw8.o: hw8.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c hw8.cc -o hw8.o

test.o: test.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c test.cc -o test.o

clean:
	rm -f gtest.a gtest_main.a *.o hw8 test

gtest-all.o: $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -I$(GTEST_DIR) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

lint:
	cpplint --filter=-legal/copyright,-build/header_guard,-build/include_subdir,-build/include_order,-runtime/string *.cc *.h

.PHONY: all clean lint
