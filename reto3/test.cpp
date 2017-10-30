#include <iostream>
#include <exception>
#include "myStack.h"

using namespace std;

void BaseTest(bool test, string base){

  if(test)
    cout << base << ": OK" << endl;
  else
    cout << base << ": FAILED" << endl;

}

bool sizeTest(){
  myStack<int> stack;
  //Test size after creation
  bool size1 = stack.size() == 0;
  stack.push(5);
  //Check that push increments size
  bool size2 = stack.size() == 1;
  stack.pop();
  //Check that pop reduces size
  bool size3 = stack.size() == 0;
  return size1 && size2 && size3;
}

bool peakTest(){
  myStack<int> stackInt;
  int peak = 4;
  bool catched = false;

  try{
    stackInt.peak();
  } catch (out_of_range & e){
    catched = true;
  }

  stackInt.push(4);

  bool pushed = stackInt.peak() == peak;

  return catched && pushed;
}

bool pushTest(){
  myStack<int> stackInt;

  int a,b;
  a = 2;
  b = 3;

  stackInt.push(a);
  stackInt.push(b);

  return stackInt.peak() == b;
}

bool popTest(){
  myStack<int> stackInt;
  int test[5] = {2,3,4,5,6};

  for(int i = 4; i >= 0; i--)
    stackInt.push(test[i]);

  bool correcto = true;
  int index = 0;
  while(!stackInt.isEmpty()){

    if(stackInt.pop() != test[index])
      correcto = false;
    index++;
  }

  return correcto;
}



int main(){

  BaseTest(sizeTest(), "Test size method");
  BaseTest(pushTest(), "Test push method");
  BaseTest(peakTest(), "Test peak method");
  BaseTest(popTest(), "Test peak method");
}
