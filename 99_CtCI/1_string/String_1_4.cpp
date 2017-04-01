/*
2017.03.21

input :"Mr John Smith     ",13
output: "Mr%20John%20Smith"
*/


#include <cstring>
#include <iostream>


using namespace std;

int main()
{
  char* str = "Mr John Smith      ";
  int length = 13;
  int index=0;
  char conv[40];


  int len = strlen(str);

  for(int i = 0; i< length; i++)
  {
    if(str[i] == ' ')
    {
      conv[index++] = '%';
      conv[index++] = '2';
      conv[index++] = '0';
    }
    else
    {
      conv[index++] = str[i];
    }
  }
  conv[index] = '\0';
  cout<<conv<<endl;
  return 0;
}
