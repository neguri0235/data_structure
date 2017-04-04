#include <iostream>
#include <cmath>
/*
input:(7-> 1 -> 6) + (5 -> 9 -> 2).That is,617 + 295.
Output: 2 -> 1 -> 9. That is, 912.
FOLLOW UP

Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
input:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
Output: 9 -> 1 -> 2. That is, 912
*/

using namespace std;

class node {
    private:
        int data;

    public:
        node* next;
        node(int i):data(i){next = nullptr;}
        int getData() { return data;}
};


int main()
{
// 617
// 295
// = 912
    int _first[3] = {7,1,6};
    int _second[3] = {5,9,2};
    int _out = 0;

    class node* first = nullptr;
    class node* second = nullptr;
    class node* sum = nullptr;
    class node* cur = nullptr;


    for(int i = 0; i<3; i++) {

        class node* p = new node(_first[i]);
        if(first == nullptr) {
            first = p;
            cur =first;
        }else {
            cur->next = p;
            cur = cur->next;
        }
     }

/*
    cur = first;
    while(cur!=nullptr) {
      cout<<cur->getData()<<" ";
      cur = cur->next;
    }
*/

    for(int i = 0; i<3; i++) {

        class node* p = new node(_second[i]);
        if(second == nullptr) {
            second = p;
            cur =second;
        }else {
            cur->next = p;
            cur = cur->next;
        }
     }

/*
    cur = second;
    while(cur!=nullptr) {
      cout<<cur->getData()<<" ";
      cur = cur->next;
    }
*/

// sum
    int _carry = 0;
    int _prev_carry = 0;

    while(first != nullptr || second != nullptr) {
        int _sum = first->getData() + second->getData();
        if(_sum > 9 ) { _carry = 1; _sum = _sum - 10;}

        class node* p = new node(_sum + _prev_carry);

        if(sum == nullptr ){
            sum = p;
            cur = sum;
        } else {
            cur->next = p;
            cur = cur->next;
        }
        _prev_carry = _carry;
        _carry = 0;

        first = first->next;
        second = second->next;
    }

    cur = sum;
    int i = 0;
    while(cur!=nullptr) {
      //cout<<cur->getData()<<endl; // debug
      _out += cur->getData() * pow(10,i);
      cur = cur->next;
      i++;
    }
    cout<<_out<<endl;




    return 0;
}
