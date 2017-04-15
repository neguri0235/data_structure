#include <iostream>

using namespace std;

void _move(int, char, char, char);

int main()
{
  _move(3,'a','b','c');
  return 0;
}

void _move(int n, char from, char to, char via) {
  if(n == 0) {
    cout<<"move 1 disk from "<<from<< " to "<<to<<endl;
    return;
  }else {
    _move(n-1,from,via,to);
    cout<<"move "<<n<<" disk from "<<from<<" to "<<to<<endl;
    _move(n-1, to,from,via);
  }
}

/*
void Hanoi(int m, char a, char b, char c){
  moves++;
  if(m == 1){
    cout << "Move disc " << m << " from " << a << " to " << c << endl;
  }else{
    Hanoi(m-1, a,c,b);
    cout << "Move disc " << m << " from " << a << " to " << c << endl;
    Hanoi(m-1,b,a,c);
  }
}
*/
