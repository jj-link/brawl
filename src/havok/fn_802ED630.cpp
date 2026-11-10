#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void* lbl_805A0EC8;
struct PtrList {
 void** data; s32 size; u32 capacity; void* items[4];
 bool isOwned() const { return (capacity & 0x80000000) == 0; }
 void dealloc() { fn_8027EABC(lbl_805A0EC8,data,capacity*4,0x15); }
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(PtrList*);
};
struct SubItem { u8 pad[0x20]; u16 flags; };
struct Item { u8 pad[0x58]; SubItem* subItem; SubItem* getSubItem() { return subItem; } };
struct Root { u8 pad[0x78]; s32 field_0x78; s32 busy; u8 pad80[4]; s8 field_0x84; };
struct Object { void** items; s32 count; u32 capacity; };
extern "C" {
int __cntlzw(unsigned int);
void fn_8027CE3C(void*, int);
void fn_802EA1F8(void*, void*);
void fn_802EFE70(Root*);
void fn_802EFF2C(void*, s8*);
void fn_802F39A0(Root*, void*);
void fn_802F9A04(Root*, void*, void*);
}
inline Item* processItem(Root* self, void* request, Item* item, Item* first) {
 SubItem* subItem = item->getSubItem();
 if ((s8)((u32)__cntlzw((unsigned int)(subItem->flags ^ 0xFFFF)) >> 5) == 0) {
  if (first == 0) { first = item; fn_802EA1F8(item->subItem, request); }
  else if (first->subItem != subItem) { fn_802F9A04(self, first, item); }
 }
 return first;
}
extern "C" void* fn_802ED630(Root* self, void* request) {
 if (self->busy != 0) {
  struct { s8 flag; s32 value; } msg;
  msg.value = (s32)request; msg.flag = 0xA;
  fn_802EFF2C(self, &msg.flag); return 0;
 }
 if (*(u16*)((u8*)request + 4) != 0) {
  s16* timer = (s16*)((u8*)request + 6); *timer = *timer + 1;
 }
 self->busy++;
 PtrList list;
 list.data = list.items; list.size = 0; list.capacity = 0x80000004;
 ((Object_vptr_0*)request)->slot3(&list);
 *(Root**)((u8*)request + 8) = self;
 Item* item; s32 offset; Item* first; s32 index;
 first=0; index=0; offset=0;
 while(index < list.size) {
  Object* object = (Object*)((u8*)*(Item**)((u8*)list.data + offset) + 0x1D8);
  if(object->count == (s32)(object->capacity & 0x3FFFFFFF)) fn_8027CE3C(object,4);
  object->items[object->count++] = request;
  item = *(Item**)((u8*)list.data + offset);
  first = processItem(self, request, item, first);
  offset += 4; index++;
 }
 if(first==0) { Item* item = (Item*)list.data[0]; fn_802EA1F8(item->subItem,request); }
 self->busy--;
 if(self->busy==0 && self->field_0x78!=0 && self->field_0x84==0) fn_802EFE70(self);
 fn_802F39A0(self,request);
 if(list.isOwned()) list.dealloc();
 return request;
}
