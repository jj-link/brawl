#include <gf/gf_heap_manager.h>
#include <string.h>
#pragma force_active on
extern "C" u16 fn_803D51A4();

struct Entry { char pad[0x88]; void* ptr; char tail[0x14]; };
struct Array { void* ptr; u16 count; u16 capacity; };
struct Obj {
 char pad0[0x40]; Heaps::HeapType heap; char pad44[4]; u16 count; char pad4a[0x32];
 Array array; char pad84[0x10]; u8 flag; u8 flag2; u16 x; u16 y; char pad9a[2];
 Entry* entries; u16 entryCount; u16 entryCapacity; char pada4[0x10]; int state;
};
extern "C" int fn_80033F18(Obj* self) {
 u16 n = fn_803D51A4();
 if (!n) return 0;
 if (self->state != 3) return 0;
 if (self->flag) return 0;
 Heaps::HeapType heap;
 u16 count;
 count = self->count;
 self->flag = 1;
 heap = self->heap;
 self->flag2 = 1;
 self->x = 0;
 self->y = 0;
 if (count) {
  if (self->entries) {
   if (self->entries) {
    for (u16 i = 0; i < self->entryCount; i++) {
     if (self->entries[i].ptr) gfHeapManager::free(self->entries[i].ptr);
    }
    gfHeapManager::free(self->entries);
    self->entries = 0;
   }
   self->entryCount = 0;
   self->entryCapacity = 0;
  }
  int size = count * 0xa0;
  self->entries = (Entry*)gfHeapManager::alloc(heap, size, 0x20);
  memset(self->entries, 0, size);
  self->entryCount = count;
  self->entryCapacity = 0;
 }
 if (&self->array) {
  if (self->array.ptr) {
   gfHeapManager::free(self->array.ptr);
   self->array.ptr = 0;
  }
  self->array.count = 0;
  self->array.capacity = 0;
 }
 int size = n * 0x2020;
 self->array.ptr = gfHeapManager::alloc(self->heap, size, 0x20);
 memset(self->array.ptr, 0, size);
 self->array.capacity = n;
 self->array.count = 0;
 return 1;
}