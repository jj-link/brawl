#include <types.h>
#pragma force_active on
struct Item {
 virtual u32 state();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual void v5();
 virtual void v6();
 virtual short id();
 virtual u32 key();
 virtual void v9();
 virtual void v10();
 virtual void v11();
 virtual void v12();
 virtual void v13();
 virtual void v14();
 virtual void v15();
 virtual void v16();
 virtual void v17();
 virtual void v18();
 virtual void v19();
 virtual void v20();
 virtual void v21();
 virtual void v22();
 virtual void v23();
 virtual void v24();
 virtual void setup(int, void*);
};
struct Entry {
 virtual void set(short, int);
 virtual void v1();
 short value;
};
struct List {
 virtual void v0();
 virtual Item** at(int);
 virtual void v2();
 virtual int size();
 virtual void v4();
 virtual void v5();
 virtual void v6();
 virtual void v7();
 virtual void v8();
 virtual void v9();
 virtual void add(Item**);
};
struct Entries {
 virtual void v0();
 virtual Entry* at(int);
 virtual void v2();
 virtual int size();
};
struct Checker {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual int test(u32);
};
struct Inner { char pad[0x28]; void* data; };
struct Sub { char pad[0x54]; Checker* checker; };
struct Context { char pad[8]; Inner* inner; char pad2[0xcc]; Sub* sub; };
struct Self { char pad[0x28]; Context* context; List* list; char pad2[4]; Entries* entries; };
inline bool contains(Self* self, u32 key) {
 for (int i = 0; i < self->list->size(); i++) {
  if (*self->list->at(i) && (*self->list->at(i))->key() == key) return true;
 }
 return false;
}
extern "C" void fn_27_94E00(Self* self, Item* item) {
 self->list->size();
 if (item->state() != 1) {
  u32 key = item->key();
  if (contains(self, key) != true) {
   item->setup(1, self->context->inner->data);
   Checker* checker = self->context->sub->checker;
   if (checker->test(item->key())) {
    self->list->add(&item);
    int count = self->entries->size();
    Entry* entry;
    for (int i = 0; i < count; i++) {
     entry = self->entries->at(i);
     if (entry->value == -1) {
      entry->set(item->id(), -1);
      return;
     }
    }
   }
  }
 }
}