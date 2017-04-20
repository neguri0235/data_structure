#include <iostream>

using namespace std;

class node {
    int data;
public:
    node* left;
    node* right;
    node (int a) : data(a) { left = nullptr; right = nullptr;}
    int getData() const { return data;}
};

void in_order(node*);
void pre_order(node*);
void post_order(node*);
int depth(node*);

int main()
{
  class node * root = new node(10);
  root->left = new node(1);
  root->right = new node(2);
  root->left->left = new node(3);
  root->left->right = new node(4);
  root->right->left= new node(5);
  root->right->right= new node(6);

//  pre_order(root); cout<<endl;
//  in_order(root); cout<<endl;
//  post_order(root); cout<<endl;
  cout<<depth(root)<<endl;

  return 0;
}

int depth(node* r){
   if (r == nullptr) return 0;
   else
   {
       int lDepth = depth(r->left);
       int rDepth = depth(r->right);
       if (lDepth > rDepth)
        return (lDepth+1);
       else
        return(rDepth+1);
  }
}
/*
int depth(node* r, int d) {
  if(r == nullptr) return 0;
  if(r->left != nullptr) return depth(r->left, d+1);
  if(r->right != nullptr) return depth(r->right, d+1);
}
*/
void pre_order(node* r) {
 if(r == nullptr) return;
 cout<<r->getData()<<" ";
 pre_order(r->left);
 pre_order(r->right);
}


void in_order(node* r) {
 if(r == nullptr) return;
 in_order(r->left);
 cout<<r->getData()<<" ";
 in_order(r->right);
}



void post_order(node* r) {
 if(r == nullptr) return;
 post_order(r->left);
 post_order(r->right);
 cout<<r->getData()<<" ";
}
