#include <iostream>
#include <vector>
using namespace std;

class node {
    public:
    node (int a) : data(a) { next = nullptr;}
    int getData( ) { return data;}
    int data;
    class node* next;
};

void print(node*);

int main()
{
  vector<int> v = {12,2,3,1,5,6,15,8,9,10,11,4,13,6,7};

  class node* head = nullptr;
  class node* cur = nullptr;

  for(int i=0; i<v.size();i++) {
    class node* p = new node(v[i]);
    if(head == nullptr) {
      head = p;
      cur = head;
    }else{
      cur->next = p;
      cur = cur->next;
    }
  }

  print(head);

  class node* left = nullptr;
  class node* right = nullptr;

  int taget = 8;

  while(head != nullptr) {
    if(head->getData() > target ) {


    }
    head = head->next;
  }


  return 0;
}

void print(node* head){
  class node* p = head;
  while(p != nullptr) {
    cout<<p->getData()<<" ";
    p = p->next;
  }


}
