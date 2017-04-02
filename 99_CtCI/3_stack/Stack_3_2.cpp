//stack. push, pop, min , O(1) time complexity

#include <iostream>

#define STACK_MAX 20
using namespace std;

class stack {
public:
  stack() { _top = 0; _min = 0;}
  void push(int a);
  int pop();
  int min();
private:
  int _stack[STACK_MAX];
  int _stack_min[STACK_MAX];
  int _top;
  int _min;
};

void stack::push(int a) {
 _stack[_top] = a; if(_top  == 0) { _min = a;} else { _min = _min < a ? _min : a;}
 _stack_min[_top] = _min;
 ++_top;
}


int stack::pop() {
  return _stack[--_top];
}

int stack::min() {
 return _stack_min[_top -1 ];
}
int main()
{
  class stack _stack;
  _stack.push(10);
  _stack.push(4);
  _stack.push(5);
  _stack.push(3);
  _stack.push(40);

  cout<<"min "<<_stack.min()<<endl;
  cout<<"pop "<<_stack.pop()<<endl;
  cout<<"min "<<_stack.min()<<endl;
  cout<<"pop "<<_stack.pop()<<endl;
  cout<<"min "<<_stack.min()<<endl;
  cout<<"pop "<<_stack.pop()<<endl;
  cout<<"min "<<_stack.min()<<endl;
  cout<<"pop "<<_stack.pop()<<endl;
  cout<<"min "<<_stack.min()<<endl;
  cout<<"pop "<<_stack.pop()<<endl;
  return 0;
}
