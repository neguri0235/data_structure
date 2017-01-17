/*
Hash function ..
lenear probing
*/

#include <iostream>

using namespace std;

#define EMPTY     -1
#define DELETED   -2
#define TBL_SIZE  20

int hash_func(int i)
{
  return i%7;
}

int hlp_init(int a[], int* np)
{
  int i;
  for(i = 0; i<TBL_SIZE; i++)
  {
    a[i] = EMPTY;
  }
  *np = 0;
  return true;
}

int hlp_insert(int key, int a[], int* np)
{
  int try1, try2;
  try1 = try2 = hash_func(key);

  while(a[try1] != EMPTY && a[try2] != DELETED)
  {
    try1 = (try1 + 1)%TBL_SIZE;

    if(try1 == try2)
      return false;
  }

  a[try1] = key;
  (*np)++;
  return try1;
}

int hlp_search(int key, int a[], int* np)
{
  int try1, try2;
  try1 = try2 = hash_func(key);

  while(a[try1] != EMPTY)
  {
    if(a[try1] == key) return try1;
    try1 = (try1+1)%TBL_SIZE;

    if(try1 == try2) return false;
  }
  return false;
}

int hlp_delete(int key, int a[], int* np)
{
  int try1;
  if(*np<0) return false;

  if( (try1 = hlp_search(key, a, np)) ==  false)
    return false;

  a[try1] = DELETED;
  (*np)--;

  return true;
}

int main()
{
  int myTbl[TBL_SIZE];
  int num;
  hlp_init(myTbl, &num);
  hlp_insert(9, myTbl, &num);
  hlp_insert(10, myTbl, &num);
  hlp_insert(11, myTbl, &num);
  hlp_insert(16, myTbl, &num);
  cout<<"data size"<<num<<endl;


  for(int i:myTbl)
    cout<<i<<" ";
  cout<<endl;

  if(hlp_search(10, myTbl, &num) == false)
    cout<<"can't find 10"<<endl;
  else
    cout<<"slot number is "<<hlp_search(10, myTbl, &num)<<endl;

  if(hlp_search(16, myTbl, &num) == false)
    cout<<"can't find 16"<<endl;
  else
    cout<<"slot number is "<<hlp_search(16, myTbl, &num)<<endl;

  if(hlp_search(17, myTbl, &num) == false)
    cout<<"can't find 17"<<endl;
  else
    cout<<"slot number is "<<hlp_search(17, myTbl, &num)<<endl;

  if(hlp_delete(16, myTbl, &num) == true)
    cout<<"delete success"<<endl;

  if(hlp_search(16, myTbl, &num) == false)
    cout<<"can't find 16"<<endl;
  else
    cout<<"slot number is "<<hlp_search(16, myTbl, &num)<<endl;
}
