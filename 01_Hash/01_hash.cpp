#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define STR_LEN 50
#define MAX_TBL 100

typedef struct _person
{
  int ssn;
  char name[STR_LEN];
  char addr[STR_LEN];
} Person;

typedef int Key;
typedef Person* value;
enum SlotStatus { EMPTY, DELETED, INUSE};

typedef int HashFunc(Key k);

typedef struct _slot
{
  Key key;
  value val;
  enum SlotStatus status;
} Slot;

typedef struct _table
{
  Slot tbl[MAX_TBL];
  HashFunc* hf;
}Table;

int GetSSN(Person* p)
{
  return p->ssn;
}

void ShowPersonInfo(Person* p)
{
  cout<<"Show Person Info"<<endl;
  cout<<p->ssn<<" ";
  cout<<p->name<<" ";
  cout<<p->addr<<endl;
}

Person* MakePersonData(int ssn, char* name, char* addr)
{
  Person* newP = new Person;
  newP->ssn = ssn;
  strcpy(newP->name,name);
  strcpy(newP->addr,addr);
  return newP;
}

void TBLInit(Table* pt, HashFunc* f)
{
  int i;
  for(i = 0; i<MAX_TBL; i++)
  {
    (pt->tbl[i]).status = EMPTY;
  }

  pt->hf = f;
}

void TBLInsert(Table* pt, Key k, value v)
{
  int hv = pt->hf(k);
  pt->tbl[hv].val = v;
  pt->tbl[hv].key = k;
  pt->tbl[hv].status = INUSE;
}

value TBLDelete(Table* pt, Key k)
{
  int hv = pt->hf(k);
  if((pt->tbl[hv]).status != INUSE)
  {
    return NULL;
  }
  else
  {
    pt->tbl[hv].status = DELETED;
    return (pt->tbl[hv]).val;
  }
}

value TBLSearch(Table* pt, Key k)
{
  int hv = pt->hf(k);
  if( (pt->tbl[hv]).status != INUSE)
    return NULL;

  return (pt->tbl[hv]).val;
}

int MyHashFunc(int k)
{
  return k%100;
}

int main()
{
  Table myTbl;

  Person* np;
  Person* sp;
  Person* rp;
  Person* qp;

  TBLInit(&myTbl, MyHashFunc);

  np = MakePersonData(780214, "choi","junggu");
  TBLInsert(&myTbl,GetSSN(np),np);

  np = MakePersonData(780224, "kim","donggu");
  TBLInsert(&myTbl,GetSSN(np),np);

  np = MakePersonData(780215, "park","namgu");
  TBLInsert(&myTbl,GetSSN(np),np);

  np = MakePersonData(780225, "Yun","seogu");
  TBLInsert(&myTbl,GetSSN(np),np);

  sp = TBLSearch(&myTbl, 780214);
  if(sp != NULL)
    ShowPersonInfo(sp);

  sp = TBLSearch(&myTbl, 780224);
  if(sp != NULL)
    ShowPersonInfo(sp);

  sp = TBLSearch(&myTbl, 780215);
  if(sp != NULL)
    ShowPersonInfo(sp);

  sp = TBLSearch(&myTbl, 780225);
  if(sp != NULL)
    ShowPersonInfo(sp);

  rp = TBLDelete(&myTbl, 780215);
  sp = TBLSearch(&myTbl, 780215);
  if(sp != NULL)
    ShowPersonInfo(sp);
    else
      cout<<"can find "<<rp->ssn<<endl;

}
