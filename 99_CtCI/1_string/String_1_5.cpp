/*

2017.03.21 initial code

*/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

char* compress(char*);

int main()
{
  char* str1 = "aabccccccccaaa"; // a2b1c8a3
  char* ret = compress(str1);
  cout<<ret<<endl;
  if(free!= NULL) free(ret);
}

char* compress(char* str)
{
  //char* com_buf = (char*)malloc(sizeof(char)*strlen(str));
  static char comp_buf[20];
  size_t len = strlen(str);
  char ch;
  int index = 0;
//  cout<<"[DEBUG] len = "<<len<<endl;
  int count = 1;

  comp_buf[0] = str[0]; // first character

  for(int i=1; i<len; i++)
  {
    ch = comp_buf[index];
    if(ch == str[i])
      count++;
    else
    {
      ++index;
      comp_buf[index] = '0'+count;
      ++index;
      comp_buf[index] = str[i];
      count = 1;
    }
  }
  ++index;
  comp_buf[index] = '0'+count;
  index++;
  comp_buf[index] = '\0';

  return comp_buf;

}
