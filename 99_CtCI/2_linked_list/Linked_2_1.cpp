#include <iostream>
#include <unordered_set>

using namespace std;

class node {
public:
  node(int a) : data(a){next = nullptr;}
  int data;
  class node* next;
};

void print(node*);
void remove_dup(node*);

int main()
{
  node* head = new node(0);
  node* cur = head;

  for(int i=0;i<20;i++) {
   node* p = new node(i*10+1);
   if(i == 6) p->data = 11; //test
   if(i == 9) p->data = 31;
   if(i == 12) p->data = 31;
   if(i == 13) p->data = 31;
   cur->next = p;
   cur = cur->next;
  }

  print(head);
  cout<<"---------------"<<endl;
  remove_dup(head);
  print(head);

  return 0;
}

void remove_dup(node* head){
  unordered_set<int> u_set;
  node* p = head;
  node* prev = nullptr;
  while(p != nullptr) {
    auto r = u_set.insert(p->data);
    if(r.second == false) {
      //duplicated

      prev->next = p->next;
      p = prev->next;
    }else {
      prev = p;
      p = p->next;
    }
  }

}

void print(node* p) {

 while(p != nullptr) {
  cout<<p->data<<" ";
  p = p->next;
 }
 cout<<endl;
}

