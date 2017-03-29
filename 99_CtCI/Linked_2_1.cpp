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

  for(int i=0;i<10;i++) {
   node* p = new node(i*10+1);
   if(i == 6) p->data = 11; //test
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
  while(p->next != nullptr) {
    auto r = u_set.insert(p->data);
    if(r.second == false) {
      //duplicated

      prev->next = p->next;
    }
    prev = p;
    p = p->next;
  }

}

void print(node* p) {

 while(p->next != nullptr) {
  cout<<p->data<<" ";
  p = p->next;
 }
 cout<<p->data<<endl;;
}
