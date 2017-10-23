CXX = g++
CPPFLAGS = -Wall -g

all: testStack

stack.o: myStack.cpp myStack.h
	$(CXX) $(CPPFLAGS) -o stack.o myStack.cpp

test.o : test.cpp
	$(CXX) $(CPPFLAGS) -o test.o test.cpp

testStack : test.o stack.o
	$(CXX) -o testStack test.o stack.o
