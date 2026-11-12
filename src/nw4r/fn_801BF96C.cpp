#pragma deadstore off
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on
struct List : nw4r::ut::detail::LinkListImpl {
 using nw4r::ut::detail::LinkListImpl::Erase;
 using nw4r::ut::detail::LinkListImpl::GetEndIter;
};
extern "C" {
void fn_8015C238(void*,int);
void fn_80204A40(void*);
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
};
extern "C" void fn_801BF96C(Self* self) {
  self->clear();
}
