#pragma deadstore off
#include <nw4r/ut/ut_LinkList.h>
#include <new>
#pragma force_active on
struct List : nw4r::ut::detail::LinkListImpl {
 using nw4r::ut::detail::LinkListImpl::Insert;
 using nw4r::ut::detail::LinkListImpl::Erase;
 using nw4r::ut::detail::LinkListImpl::GetEndIter;
};
struct Node { nw4r::ut::LinkListNode node; List list; };
struct Head { unsigned prev; unsigned next; };
extern "C" {
void fn_8015C238(void*,int);
void* fn_802049BC(unsigned,unsigned,int);
void fn_80204A40(void*);
void* fn_80204A70(void*,int,int);
void fn_80204B90(void*,int);
}
struct Item { int p; Item* next; int a; void (*fn)(void*,int,int); int e; };
struct Cleanup { int a,b,c; Item* head; };
struct Self {
 void* h; List list;
 void clear() {
  if(h) {
   if(!list.IsEmpty()) {
    nw4r::ut::LinkListNode* end=list.GetEndIter().operator->();
    while(!list.IsEmpty()) {
     Cleanup* n=(Cleanup*)end->GetPrev();
     if(n) {
      Item* it=(Item*)((char*)n+12);
      while(it!=n->head) {
       it=it->next;
       if(it && it->fn) it->fn((char*)it+32,it->a,it->e);
      }
      if((char*)n+8) fn_8015C238((char*)n+8,0);
     }
     list.Erase((nw4r::ut::LinkListNode*)n);
    }
   }
   fn_80204B90(h,3); fn_80204A40(h); h=0;
  }
 }
 bool add() {
  void* p=fn_80204A70(h,20,4);
  if(!p) return false;
  Node* n=(Node*)p;
  if(n) {
   unsigned* w=(unsigned*)n;
   Head* hd=(Head*)(w+3);
   unsigned tail=(unsigned)hd;
   w[0]=0; w[1]=0; hd->prev=0; hd->next=0; w[2]=0; hd->prev=tail; hd->next=tail;
  }
  list.Insert(list.GetEndIter(),&n->node);
  return true;
 }
};
extern "C" int fn_801BF7D0(Self* self,unsigned base,unsigned size) {
 if(self->h) self->clear();
 unsigned s=(base+3)&~3u;
 unsigned e=base+size;
 if(s>e) return 0;
 self->h=fn_802049BC(s,e-s,0);
 if(!self->h) return 0;
 if(!self->add()) return 0;
 return 1;
}
