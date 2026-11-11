#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
extern "C" void fn_8027CD94(void*, s32, s32);
extern "C" void fn_8027CE3C(void*, s32);
extern "C" void fn_802EA824(void*, void*);
extern "C" void fn_802EFE70(void*);
extern "C" void fn_802FA940(void*, void*);
extern "C" void fn_802FAD24(void*, void*);
extern "C" void fn_802FF53C(void*, void*);
class Object_vptr_0 { public: virtual void slot0(int); };
struct TimerEntry { char* name; u32 time; u32 unused; };
struct TimerState { u32 unused0; TimerEntry* current; u32 unused8; TimerEntry* end; u32 unused10[2]; };
extern TimerState lbl_80532448;
extern char lbl_80414120[];
struct Node;
struct Contact;
struct ArrayHeader { void** items; s32 count; };
template <class T> struct Array {
 T* items; int count; unsigned int capacity;
 inline void setSize(int n) {
  ArrayHeader* array = (ArrayHeader*)this;
  int cap = capacity & 0x3FFFFFFF;
  if (cap < n) fn_8027CD94(array, n < cap * 2 ? cap * 2 : n, 4);
  array->count = n;
 }
};
struct Ref { char pad[8]; Node* owner; };
struct Flags { u8 hi:2; u8 mid:2; u8 low:2; u8 bottom:2; };
struct Node {
 Object_vptr_0* vtable; char pad04[0x1C]; u16 id; u16 parentId;
 u8 byte24; u8 byte25; union { u8 flags26; Flags bits26; }; union { u8 flags27; Flags bits27; };
 char pad28[0x10]; Node** arr38; s32 count3C; u32 capacity40; u32 unk44; u32 unk48;
 char pad4C[0x0C]; Node* owner58; char pad5C[4];
 Array<void*> array60; Contact* contactArray6C; s32 contactCount70;
 char pad74[0x1C]; u16 index90;
};
struct Contact { Ref* ref; char pad[0x20]; };
inline int joinedFlags(Node* dst, Node* src) {
 int result = 1;
 if (((signed char)((dst->flags27 >> 6) & 3) == 0) && ((signed char)((src->flags27 >> 6) & 3) == 0)) result = 0;
 return result;
}
struct Manager {
 char pad00[0x1C]; s32 total; char pad20[8]; Node** primary; char pad2C[8];
 Node** queue; s32 qcount; u32 qcapacity; Node** parents; u32 parentCount; u32 parentCapacity;
 char pad4C[0x2C]; s32 pending; s32 depth; char pad80[4]; u8 enabled;
};
inline void record(int offset) {
 TimerState* timer = &lbl_80532448;
 TimerEntry* entry = timer->current;
 if ((signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)entry)) >> 31)) {
  entry->name = lbl_80414120 + offset;
  register u32 t;
  asm { mftb t }
  entry->time = t;
  timer->current = entry + 1;
 }
}
extern "C" void* fn_802F9A5C(Manager* self, Node* dst, Node* src) {
 int joined;
 record(0);
 if (dst->count3C <= src->count3C && (dst->count3C < src->count3C || dst->id > src->id)) {
  Node* tmp = dst; dst = src; src = tmp;
 }
 self->depth++;
 int hasDst = 1;
 if ((dst->flags26 & 3) == 0 && (src->flags26 & 3) == 0) hasDst = 0;
 joined = joinedFlags(dst, src);
 if (hasDst) {
  if ((dst->flags26 & 3) == 0) {
   dst->bits27.hi = 1;
   fn_802FA940(self, dst);
   dst->byte24 = src->byte24; dst->byte25 = src->byte25;
  } else if ((src->flags26 & 3) == 0) {
   src->bits27.hi = 1;
   fn_802FA940(self, src);
  } else {
   u8 a = src->byte24;
   if (dst->byte24 < a) a = dst->byte24;
   dst->byte24 = a;
   u8 b = src->byte25;
   if (dst->byte25 < b) b = dst->byte25;
   dst->byte25 = b;
  }
 }
 fn_802FF53C((char*)dst + 0x48, (char*)src + 0x48);
 int index = (u16)dst->count3C;
 s32 newCount = dst->count3C + src->count3C;
 void* array = (char*)dst + 0x38;
 u32 capacity = dst->capacity40 & 0x3FFFFFFF;
 if ((s32)capacity < newCount) {
  s32 doubled = capacity * 2;
  fn_8027CD94(array, newCount < doubled ? doubled : newCount, 4);
 }
 *(s32*)((char*)array + 4) = newCount;
 for (s32 i = 0; i < src->count3C; i++) {
  dst->arr38[index & 0xFFFF] = src->arr38[i];
  src->arr38[i]->owner58 = dst;
  src->arr38[i]->index90 = index;
  index++;
 }
 index = dst->array60.count;
 dst->array60.setSize(index + src->array60.count);
 for (s32 i = 0; i < src->array60.count; i++) {
  if (src->array60.items[i]) {
   dst->array60.items[index] = src->array60.items[i];
   *(Node**)((char*)dst->array60.items[index] + 12) = dst;
   index++;
  }
 }
 dst->array60.setSize(index);
 for (s32 i = 0; i < src->count3C; i++) {
  Node* child = src->arr38[i];
  Contact* contacts = child->contactArray6C;
  for (s32 j = child->contactCount70 - 1; j >= 0; j--) {
   contacts->ref->owner = dst;
   contacts++;
  }
 }
 fn_802EA824(dst, src);
 *(s32*)((char*)dst + 0x1C) += *(s32*)((char*)src + 0x1C);
 *(s32*)((char*)src + 0x1C) = 0;
 char* queue;
 u16 srcId;
 if (src->flags26 & 3) {
  srcId = src->id;
  queue = (char*)self + 0x28;
 } else {
  queue = (char*)self + 0x34;
  srcId = src->id;
 }
 s32 queueCount = *(s32*)(queue + 4);
 s32 last = queueCount - 1;
 if ((s32)srcId < last) {
  Node** arr = *(Node***)(queue);
  arr[srcId] = arr[last];
  (*(Node***)(queue))[srcId]->id = srcId;
 }
 --*(s32*)(queue + 4);
 int flag = 0;
 if ((((dst->flags26 >> 6) & 3) != 0) || (((src->flags26 >> 6) & 3) != 0)) flag = 1;
 dst->bits26.hi = flag;
 flag = 0;
 if ((((dst->flags26 >> 4) & 3) != 0) || (((src->flags26 >> 4) & 3) != 0)) flag = 1;
 dst->bits26.mid = flag;
 dst->bits27.hi = joined != 0;
 if (src->parentId != 0xFFFF && dst->parentId == 0xFFFF) {
  dst->parentId = (u16)self->parentCount;
  if ((s32)self->parentCount == (s32)(self->parentCapacity & 0x3FFFFFFF)) fn_8027CE3C((char*)self + 0x40, 4);
  self->parents[self->parentCount++] = dst;
 }
 fn_802FAD24(self, src);
 if (src) ((Object_vptr_0*)src)->slot0(1);
 if (dst->flags26 & 3) {
  int oldId = dst->id;
  if (oldId != 0) {
   Node* first = *self->primary;
   if (dst->count3C > first->count3C) {
    dst->id = 0; first->id = oldId;
    *self->primary = dst; self->primary[oldId] = first;
   }
  }
 }
 record(12);
 self->depth--;
 if (self->depth == 0 && self->pending && (signed char)self->enabled == 0) fn_802EFE70(self);
 return dst;
}
