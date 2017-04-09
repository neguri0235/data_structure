#include <iostream>
#include <vector>

using namespace std;

class node {
    public:
    int data;
    class node* left;
    class node* right;
    node(int a) : data(a) { left = nullptr; right = nullptr;}
    int getData() { return data;}
};
void traverse_post_order(node*);
void traverse_pre_order(node*);
void traverse_in_order(node*);

int main()
{
  vector<int> v = {10,2,6,15,18,1,7,12,8,14,9,3};
  class node* root = nullptr;
  class node* parent = nullptr;

//build tree;
  for(int i=0; i<v.size();i++) {
    class node* p = new node(v[i]);

    if(root == nullptr) {
        root = p;
        parent = p;
    } else {
        parent = root;
        while(1) {
            if(parent->getData()< p->getData()) {
            //left child
              if(parent->left == nullptr ){
                parent->left = p;
                break;
              } else {
                // mode left child
                parent = parent->left;
              }
            }else{
            //right child
              if(parent->right == nullptr) {
                parent->right = p;
                break;
              }else {
                parent = parent->right;
              }
            }
        }
     }
  }

// traverse;
  traverse_in_order(root); cout<<endl;
  traverse_pre_order(root); cout<<endl;
  traverse_post_order(root); cout<<endl;
  return 0;
}

void traverse_in_order(node* r) {
  if(r == nullptr) return;
  traverse_in_order(r->left);
  cout<<r->getData()<<" ";
  traverse_in_order(r->right);
}

void traverse_pre_order(node* r) {
  if( r == nullptr) return ;
  cout<<r->getData()<<" ";
  traverse_pre_order(r->left);
  traverse_pre_order(r->right);
}

void traverse_post_order(node* r) {
  if( r == nullptr) return ;
  traverse_post_order(r->left);
  traverse_post_order(r->right);
  cout<<r->getData()<<" ";
}
