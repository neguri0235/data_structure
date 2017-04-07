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
  cout<<"999"<<endl;
  print(head);

  cout<<"lll"<<endl;
  class node* left = nullptr;
  class node* right = nullptr;
  class node* left_head = nullptr;

  int target = 8;
  int i = 0;
  while(head != nullptr) {
    class node* move = head;
    head= head->next;
    cout<<"input "<<i++<<" "<<move->getData()<<"  -> ";
    if(move->getData() > target ) {
        cout<<"right"<<endl;
        if(right == nullptr) {
            right = move;
            right->next = nullptr;
        }else {
            move->next = right;
            right = move->next;
        }
    }else {
        cout<<"left"<<endl;
        if(left_head == nullptr) {
            left = move;
            left_head = move;
        }else{
            left->next = move;
            left = left->next;
        }
    }
  }
  cout<<"992"<<endl;
  left->next = right;

  print(left_head);
  return 0;
}

void print(node* head){
  class node* p = head;
  while(p != nullptr) {
    cout<<p->getData()<<" ";
    p = p->next;
  }
  cout<<endl;

}
