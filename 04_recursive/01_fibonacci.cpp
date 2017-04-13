#include <iostream>
#include <vector>

using namespace std;

vector<int> v(50, -1);

int fib_1(int);
int fib_2(int);
int fib_3(int);

int main()
{
  v[0]= 0;
  v[1]= 1;
  v[2]= 1;

  cout<<fib_1(44)<<endl;
  cout<<fib_2(44)<<endl;
  cout<<fib_3(44)<<endl;
  return 0;
}

int fib_1(int a) {
  if(a == 1 || a == 2) return 1;
  else {
  return fib_1(a-2) + fib_1(a-1);
  }
}


int fib_2(int a) {
  if( a==1 || a == 2) return v[a];
  else {
    if(v[a] == -1) {
      v[a] = fib_2(a-2) + fib_2(a-1);
    }
    return v[a];
  }
}


int fib_3(int a) {
  v.clear();
  v.push_back(0);
  v.push_back(1);
  v.push_back(1);
  for(int i = 3; i<=a; i++) {
   v[a] = v[a-2] + v[a-1];
  }
  return v[a];
}


