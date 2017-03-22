#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

/*C*/
using namespace std;

void reverse(char*);

int main()
{
  char* str1 = "abcdefg";
  char* str2 = "HelloWorld";

  reverse(str1);
  reverse(str2);
  return 0;
}

void reverse(char* s)
{
  int len = strlen(s);
  char* str = (char*)malloc(sizeof(char)*len+1);
  for(int i=len-1; i>=0; i--)
  {
    str[len - i -1] = s[i];
  }
  str[len] = '\0';
  printf("%s\n",str);
  free(str);
}
