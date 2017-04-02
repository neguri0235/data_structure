#include <iostream>
#include <random>
#include <chrono>
#include <cstring>
#include <cstdio>

using namespace std;

// linked list
/*
K 값을 갖는 노드를 기준으로 연결 리스트를 나누는 코드를 작성하라. x 보다 작은 값을 갖는 노노드가
x와 같거나 큰 노드들 보다 앞에 오록 하면 된다.
*/

class node {
public:
  node(int a):data(a) { next = nullptr;}
  int data;
  node* next;
};

default_random_engine dre (chrono::steady_clock::now().time_since_epoch().count());     // provide seed
int random (int lim)
{
    uniform_int_distribution<int> uid {0,lim};   // help dre to generate nos from 0 to lim (lim included);
    return uid(dre);    // pass dre as an argument to uid to generate the random no
}

void print(node*);
node* find_node(node*,int);
node* traverse(node*,node*);

int main()
{
  // init
  class node* head = new node(0);
  class node* cur = head;

  for(int i=0; i<20; i++) {
    cur->next = new node(random(20));
    cur = cur->next;
  }
  print(head);

  class node* target = find_node(head,10);
  if(target != nullptr) cout<<"target::"<<target->data<<endl;

  head = traverse(head,target);
  print(head);

  return 0;
}

node* traverse(node* head, node* target) {

    class node* mov = nullptr;
    class node* cur = head;
    class node* pre = head;

    while(cur != target) {
//          cout<<"read data "<<cur->data<<" ";
//         getchar();
        if(cur->data > target->data) {
          //backup left
          cout<<"# DEBUG LEFT "<<cur->data<<endl;
          mov = cur;
          pre->next = cur->next;
          cur = cur->next;

          //move right
          mov->next = target->next;
          target->next = mov;
          print(head);
        } else {
          pre = cur;
          cur = cur->next;
        }
    }

    while(cur != nullptr) {

      if(cur->data < target->data) {
        cout<<"# DEBUG RIGHT "<<cur->data<<endl;

        //remove cur
        mov = cur;
        pre->next = mov->next;
        cur = cur->next;
        //move left
        mov->next = head;
        head =mov;
        print(head);
      } else {
       cur = cur->next;
      }
    }
 return head;
}



node* traverse0401(node* head, node* target) {
  class node* cur = head;
  class node* move = nullptr;
  class node* prev = head;

  // before target

  while(cur != target) {

    if(cur->data > target->data) {
      if(cur == head) head = head->next;
      move = cur;
      cur = cur->next;
      move->next = target->next;
      target->next = move;
    }
    prev = cur;
    cur = cur->next;
  }
  //afer target
  cur = target;
  while(cur!=nullptr) {

    if(cur->data < target->data) {
      move = cur;
      move->next = head->next;
      head = move;
    }

  }

  return head;
}


node* traverse0331(node* head, node* target) {
  node* prev = head;
  node* return_head = head;

  while(head != target) {
    if(target->data < head->data) {
        cout<<head->data<<endl;
        prev->next = head->next;
        head->next = target->next;
        target->next = head;
        head = prev;
    }
    head = head->next;
  }
  head = target->next;

  while(head != nullptr) {

    if(target->data > head->data) {

    }

    head = head->next;
  }

  return return_head = target;
}


node* find_node(node* head, int a) {
  while(head->data != a && head != nullptr) {
    head = head->next;
  }
  return head != nullptr ? head : nullptr;
}

void print(node* p) {
  while(p != nullptr) {
    cout<<p->data<<" ";
    p = p->next;
  }
  cout<<endl;
}
