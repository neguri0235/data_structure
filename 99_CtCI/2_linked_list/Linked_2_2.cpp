#include <iostream>

using namespace std;


class node {
public:
  node(int a) : data(a) { next = nullptr;}

  node* next;
  int data;
};

void print(node*);
int find(node*,int);

int main()
{
  class node* head = new node(0);
  class node* cur = head;
  //build item
  for(int i = 0; i<20; i++) {
    class node* p = new node(i+1);
    cur->next = p;
    cur = cur->next;
  }

  print(head);

  // find nth item from last
  cout<<find(head,3)<<endl;
  cout<<find(head,7)<<endl;
  cout<<find(head,13)<<endl;

  return 0;
}

int find(node* head, int n) {
  node* to_end = head;
  node* from_start = head;

  for(int i=0; i<n;i++){
     to_end = to_end->next;
  }
  //cout<<"##DEBUG:: to end init data "<<to_end->data<<endl;

  // mode to end
  while(to_end->next!=nullptr) {
    to_end = to_end->next;
    from_start = from_start->next;
  }


  return from_start->data;
}


void print(node* p) {

  while(p!=nullptr) {
    cout<<p->data<<" ";
    p = p->next;
   }
   cout<<endl;
}
