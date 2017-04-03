// single linked list
#include <iostream>

using namespace std;

class node {
public:
  node(int a) : data(a) { next = nullptr;}
  int getData( ) {return data;}
  void setData(int a) { data = a;}

  int data;
  class node* next;
};

void print_list(node*);
void print_list_recursive(node*);
void remove_all(node*);
void remove_data(node*, int);


int main()
{
  class node* head = new node(0);
  class node* cur = head;

  // init data
  for(int i=0; i< 10; i++ ) {
    class node* p = new node(i+1);
    cur->next = p;
    cur = cur->next;
  }

  // traverse
  print_list(head);

  // remove data
  remove_data(head, 5);
  remove_data(head, 25);
  print_list_recursive(head);

  // remove all list
  remove_all(head);

  return 0;
}

void print_list(node* p) {
  while(p != nullptr) {
    cout<<p->getData()<<" ";
    p = p->next;
  }
  cout<<endl;
}

void print_list_recursive(node* p) {
  if(p == nullptr)
    return ;
  else{
    cout<<p->getData()<<" ";
    print_list_recursive(p->next);
  }
}


void remove_all(node* p) {
  class node* del_next;
  while(p!=nullptr) {
   del_next = p->next;
   delete p;
   p = del_next;
  }
}

void remove_data(node* p, int del_data) {
  cout<<"remove data "<<del_data<<endl;

  class node* pre_node = p;

  while(p != nullptr && p->getData() != del_data ) {
    pre_node = p;
    p = p->next;

  }

  if(p == nullptr) {cout<<del_data<<" is not found"<<endl; return;}
  pre_node->next = p->next;
  delete p;
}
