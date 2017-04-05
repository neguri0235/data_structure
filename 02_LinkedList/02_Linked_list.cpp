/*double linked list*/

#include <iostream>
using namespace std;

class node {
    public:
    node(int a):data(a) { next = nullptr; prev = nullptr;}
    class node* next;
    class node* prev;
    int getData( ) { return data;}
    private:
    int data;
};

node* print_list(node*);
void print_list_recursive(node*);
void remove_all(node*);
void remove_data(node*, int);

void print_reverse_list(node*);


int main()
{
  class node* head = nullptr;
  class node* curr = nullptr;

  for(int i = 0; i<10; i++) {
    class node* p = new node(i+10);
    if(head == nullptr) {
      head = p;
      curr = p;
    }else {
      curr->next = p;
      p->prev = curr;

      //prev = curr;
      curr =curr->next;

    }
  }
  class node* tail = nullptr;
  tail = print_list(head);
  print_reverse_list(tail);
  return 0;
}

node* print_list(node* head) {
    class node* p = head;
    class node* tail= nullptr;
    while(p!=nullptr) {
    cout<<p->getData()<<" ";
    tail = p;
    p = p->next;
    }
    cout<<endl;
    return tail;
}

void print_reverse_list(node* tail){
    class node* p = tail;
    while(p != nullptr) {
    cout<<p->getData()<<" ";
    p = p->prev;
    }
    cout<<endl;
}
