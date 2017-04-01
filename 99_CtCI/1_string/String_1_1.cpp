#include <iostream>
#include <cstring>
#include <bitset>
#include <unordered_set>

using namespace std;

int check_bitset(char*);
int check_set(char*);

int main()
{
  char* str1 = "abcdefghi";
  char* str2 = "abcdefghia";

  int ret1 = check_bitset(str1);
  int ret2 = check_bitset(str2);
  cout<<"bit "<<ret1<<"  "<<ret2<<endl;


  ret1 = check_set(str1);
  ret2 = check_set(str2);
  cout<<"set "<<ret1<<"  "<<ret2<<endl;

  return 0;
}


int check_set(char* s)
{
   int len = strlen(s);
   unordered_set<char> u_set;
   for(int i = 0; i<len; i++) {
    auto ret = u_set.insert(s[i]);
    if(ret.second == false) return 0;
   }
   return 1;
}

int check_bitset(char* s)
{
  int len = strlen(s);
  bitset<256> b_set;

  for(int i=0; i<len;i++) {
    if(b_set[s[i]] == true) return 0;
    b_set[s[i]] = true;
  }
  return 1;
}
