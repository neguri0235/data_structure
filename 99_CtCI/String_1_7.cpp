#include <iostream>

using namespace std;


int map[8][8] {
{ 1,1,1,1,1,1,1,1},
{ 1,1,1,1,1,1,1,1},
{ 1,1,1,1,1,1,0,1},
{ 1,1,0,1,1,1,1,1},
{ 1,1,1,1,1,1,1,1},
{ 1,1,1,1,0,1,1,1},
{ 1,1,1,1,1,1,1,1},
{ 1,1,1,1,1,1,1,1}
};

void solve();
void print();
void fill(int,int);
void change();
int main()
{
  print();
  cout<<endl<<endl;
  solve();
  print();
  return 0;
}

void print()
{
  for(int i=0;i<8;i++) {
    for(int j=0;j<8;j++) {
    cout<<map[i][j]<<" ";
   }
   cout<<endl;
 }
}
void solve()
{
  for(int i=0;i<8;i++) {
    for(int j=0;j<8;j++) {
       if(map[i][j] == 0) fill(i,j);
    }
  }
  change();
}

void fill(int y,int x)
{
  for(int i=0; i<8; i++) {
    map[y][i] = 2;
  }

  for(int i=0; i<8; i++) {
    map[i][x] = 2;
  }
}

void change()
{
  for(int i=0; i<8;i++) {
    for(int j=0;j<8;j++) {
      if(map[i][j] == 2) map[i][j] = 0;
    }
  }
}
