#include <iostream>
#include <algorithm>

using namespace std;

int isanagram(string,string);

int main()
{
  string str1 = "dog";
  string str2 = "god";
  string str3 = "hello";
  string str4 = "hellow";
  string str5 = "samdasoo";
  string str6 = "asmadsoo";

  cout<<isanagram(str1,str2)<<endl;
  cout<<isanagram(str3,str4)<<endl;
  cout<<isanagram(str5,str6)<<endl;

  return 0;
}

int isanagram(string s1, string s2)
{
  if(s1.length() != s2.length())
    return 0;

  sort(s1.begin(),s1.end());
  sort(s2.begin(),s2.end());
  if(s1.compare(s2) == 0)
   return 1;
}
