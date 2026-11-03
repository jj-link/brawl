#include <types.h>
#pragma force_active on
class SoHeapAllocator {
public:
 virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3();
 virtual void* alloc(s32, s32);
};
extern SoHeapAllocator* lbl_805A0EB8;
extern "C" float fn_802D27FC(void*);
extern "C" const float lbl_805A45B8;
class Class_80302A88 {
public:
 static void operator delete(void* p);
 static void* operator new(unsigned long size) {
  void* p = lbl_805A0EB8->alloc(size, 0x25);
  ((unsigned short*)p)[2] = size;
  return p;
 }
};
extern "C" char lbl_80487408[];
struct Vtable_Class_802CEBE0 {
 void* vtable;
 unsigned short type;
 char padding[0x2a];
 Vtable_Class_802CEBE0() : vtable(lbl_80487408) {}
};
class Class_802CEBE0 : public Vtable_Class_802CEBE0, public Class_80302A88 {
public:
 Class_802CEBE0(int, int, float);
};
struct Item {
 char pad[0xc];
 float value;
 char pad2[0x10];
 char a[0x10];
 char b[1];
};
inline float calc(Item* p) { float v = p->value; float result = fn_802D27FC(p); return result + v; }
struct Node {
 Item* item;
 int field4;
 int field8;
 Node* next;
};
struct List { Node* node; };
extern "C" void fn_80302950(List** lists, int* flags, Node* nodes, Node** out) {
 for (int i = 0; i < 2; ++i) {
  if (flags[i]) {
   Item* item = lists[i]->node->item;
   Class_802CEBE0* object0 = new Class_802CEBE0((int)&item->a, (int)&item->b, lbl_805A45B8 + (calc(item)));
   if (&nodes[i]) {
    Node* n = lists[i]->node;
    int value = n->field8;
    nodes[i].next = n;
    nodes[i].field8 = value;
   }
   nodes[i].field4 = nodes[i].next->field4;
   nodes[i].item = (Item*)object0;
   out[i] = lists[i]->node;
   lists[i]->node = &nodes[i];
  } else {
   out[i] = 0;
  }
 }
}