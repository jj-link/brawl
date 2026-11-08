#include <types.h>
#pragma force_active on
class Node;
class NodeBase {
public:
 Node* next;
 char pad[12];
 union {
  struct { signed int count:4; unsigned int other:28; } bits;
  unsigned char flags;
 } state;
};
class Node: public NodeBase {
public:
 virtual void unused();
 virtual void* getResource();
 virtual void unused2();
 virtual void finish();
};
struct Owner { char pad[0x320]; int timer; int enabled; };
struct Iterator {
 NodeBase* node;
 Node* operator->() const { return (Node*)node; }
 void operator++(){node=node->next;}
 bool operator!=(const Iterator& o) const {return node!=o.node;}
};
struct List {
 NodeBase* head;
 Iterator begin(){Iterator i={head}; return i;}
 Iterator end(){Iterator i={0}; return i;}
};
extern "C" {
extern unsigned char lbl_8049E560[0x10];
int fn_800B61C0(void*);
}
extern "C" void fn_80104784(Owner* self){
 int timer=self->timer;
 if(timer>=0 && self->enabled!=0){
  int value=timer-1;
  self->timer=value>-1?value:-1;
 }
 int state=2;
 List& list=*(List*)lbl_8049E560;
 Iterator it=list.begin();
 Iterator end=list.end();
 while(it!=end){
  if(it->state.bits.count>0){
   --it->state.bits.count;
   if(it->state.bits.count<=0) it->state.flags|=8;
  }else{
   if(fn_800B61C0(it->getResource())){
    it->finish();
    it->state.bits.count=state;
   }
  }
  ++it;
 }
}