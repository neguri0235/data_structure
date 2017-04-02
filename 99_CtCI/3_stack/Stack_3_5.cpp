// two stack => one queue
#include <iostream>
using namespace std;

class stack {
public:
  stack():_pos(0){}
  void push(int a) { _stack[_pos++] = a;}
  int pop() { return _stack[--_pos];}
  int getPos() { return _pos - 1;}
private:
  int _stack[30];
  int _pos;
};

class queue {
public:
  queue() {
  }
  void enqueue(int a);
  int dequeue();
  class stack _stack1;
  class stack _stack2;
};

void queue::enqueue(int a) {
  _stack1.push(a);
}

int queue::dequeue(){
  int  _getPos1 = _stack1.getPos();

  for(int i= 0; i<=_getPos1; i++) {
    _stack2.push(_stack1.pop());
  }
  int _que = _stack2.pop();

  int  _getPos2 = _stack2.getPos();

  for(int i = 0; i<=_getPos2; i++) {
  _stack1.push(_stack2.pop());
  }
  return _que;
}

int main()
{
  class queue _queue;
  _queue.enqueue(10);
  _queue.enqueue(20);
  _queue.enqueue(30);
  _queue.enqueue(40);
  _queue.enqueue(50);

  cout<<_queue.dequeue()<<endl;
  cout<<_queue.dequeue()<<endl;
  cout<<_queue.dequeue()<<endl;
  cout<<_queue.dequeue()<<endl;
  cout<<_queue.dequeue()<<endl;
  return 0;
}
