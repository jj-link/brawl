#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void slot6(int, int);
 virtual void slot7(); virtual void slot8();
 virtual void slot9(void*, int);
 virtual void slot10(void*, int);
};
struct Entry { int id; void* a; void* b; };
struct List { unsigned int count; Entry* entries; };
struct Modules { char pad[0x14]; Object_vptr_0* first; char pad2[8]; Object_vptr_0* second; };
struct Self { char pad[0x180]; Modules* modules; char pad2[4]; List* list; };
extern "C" void fn_27_26320C(Self* self) {
 if (self->list->entries != 0) {
  int off;
  unsigned int i;
  i = 0;
  off = 0;
  while (i < self->list->count) {
   Entry* base = self->list->entries;
   Entry* entry = (Entry*)((char*)base + off);
   if (entry->a != 0) {
    self->modules->second->slot10(entry->a, base[i].id);
   } else if (entry->b != 0) {
    self->modules->second->slot9(entry->b, base[i].id);
   }
   off += 12;
   i++;
  }
 }
 self->modules->first->slot6(2, 0);
}