#include <iostream>

using namespace std;

constexpr int _size_stack = 30;
int _stack[_size_stack];

class stack {
 private:
 int _bottom;
 int _top;
 int _pos;
 public:
 stack(int nth_stack,int tot_stack) {
  _bottom = (_size_stack/3)*nth_stack;
  _top = (_size_stack/3)*(nth_stack+1)-1;
  _pos = _bottom;
 }

 void push(int a) {
  if(_pos >= _top) {cout<<"stack overflow"<<endl; return; }
  _stack[_pos++] = a; }

 int pop() {
  if(_pos <= _bottom) { cout<<"stack underflow"<<endl; return -99;}
  return _stack[--_pos];
 }
};


int main()
{
    stack _st1(0,3);
    stack _st2(1,3);
    stack _st3(2,3);

    _st1.push(1);
    _st1.push(2);
    _st1.push(3);

    _st2.push(10);
    _st2.push(20);
    _st2.push(30);

    _st3.push(100);
    _st3.push(200);
    _st3.push(300);

    cout<<_st1.pop()<<" "<<_st1.pop()<<" "<<_st1.pop()<<" "<<endl; cout<<_st1.pop()<<endl;
    cout<<_st2.pop()<<" "<<_st2.pop()<<" "<<_st2.pop()<<" "<<endl; cout<<_st2.pop()<<endl;
    cout<<_st3.pop()<<" "<<_st3.pop()<<" "<<_st3.pop()<<" "<<endl; cout<<_st3.pop()<<endl;
        return 0;
}
