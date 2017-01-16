#include <iostream>

using namespace std;



struct info
{
  unsigned int number;
  unsigned int age;
};

int GetHashValue(unsigned int i)
{
  return i%1000;
}

int main()
{
  struct info empInfo[1000];
  struct info _emp;


  info _emp1 = {20120003, 42};
  info _emp2 = {20120083, 38};
  info _emp3 = {20120014, 27};
  info _emp4 = {20120092, 24};


  //empInfo[_emp1.number] = _emp1;
   empInfo[GetHashValue(_emp1.number)] = _emp1;
   empInfo[GetHashValue(_emp2.number)] = _emp2;
   empInfo[GetHashValue(_emp3.number)] = _emp3;
   empInfo[GetHashValue(_emp4.number)] = _emp4;

   cout<<empInfo[GetHashValue(_emp1.number)].age<<endl;
   cout<<empInfo[GetHashValue(_emp2.number)].age<<endl;
   cout<<empInfo[GetHashValue(_emp3.number)].age<<endl;
   cout<<empInfo[GetHashValue(_emp4.number)].age<<endl;
}
