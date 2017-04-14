#include <iostream>

using namespace std;

int fact(int);

int main()
{
  cout<<fact(4)<<endl;
  cout<<fact(10)<<endl;
  cout<<fact(7)<<endl;
  return 0;
}

int fact(int i) {
    if(i == 1) return 1;
    else {
     return i*fact(i-1);
    }
}
