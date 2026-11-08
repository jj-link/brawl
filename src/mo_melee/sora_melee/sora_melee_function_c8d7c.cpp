#include <types.h>
#pragma force_active on
struct Unit { u8 inUse:1; u8 pad[19]; s8 prev; s8 next; u8 pad2[2]; };
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual s32 capacity(); virtual bool isFull();
union { s32 packed; struct { s32 m_freeIndex:5; s32 m_topIndex:5; s32 m_lastIndex:5; s32 m_size:5; }; };
s32 getFreeIndex() const { return m_freeIndex; }
Unit m_units[10];
};
extern "C" s32 fn_27_C8D7C(Object_vptr_0* self,s32 index) {
if(self->isFull()==true)return -1;
if(index<0){s32 freeIndex=self->getFreeIndex();self->m_freeIndex=self->m_units[self->m_freeIndex].next;if(self->m_freeIndex>0)self->m_units[self->m_freeIndex].prev=-1;self->m_size++;return freeIndex;}
if(index>=self->capacity())return -1;
Unit& curr=self->m_units[index];
if(static_cast<bool>(curr.inUse)==true)return -1;
s32 next=curr.next; s32 prev=curr.prev;
if(prev<0&&next<0)self->m_freeIndex=-1;
else if(prev<0){self->m_units[next].prev=-1;self->m_freeIndex=curr.next;}
else if(next<0)self->m_units[prev].next=-1;
else{self->m_units[prev].next=next;self->m_units[next].prev=prev;}
self->m_size++;return index;
}