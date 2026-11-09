#pragma force_active on
#pragma use_lmw_stmw on
extern "C" void fn_802EFE70(void*);
class Object_vptr_0 { public: virtual void slot0(); virtual void slot1(void*); virtual void slot2(void*); };
struct Node {
 char pad[0x1C0]; Object_vptr_0** inners; int innerCount;
 void removeAt(int index) { --innerCount; for (int j = index; j < innerCount; ++j) inners[j] = inners[j + 1]; }
 void cleanup() { for (int i = innerCount - 1; i >= 0; --i) if (inners[i] == 0) removeAt(i); }
};
struct Holder { char pad[0x38]; Node** nodes; int nodeCount; };
struct Main {
 char pad0[0x78]; int f78; int counter; char pad1[4]; char f84; char pad2[0x114 - 0x85]; Object_vptr_0** items; int count;
 void removeAt(int index) { --count; for (int j = index; j < count; ++j) items[j] = items[j + 1]; }
 void cleanup() { for (int i = count - 1; i >= 0; --i) if (items[i] == 0) removeAt(i); }
};
extern "C" void fn_802F4940(void* a0, void* a1) {
 int k, c;
 Holder* arg = (Holder*)a1;
 Main* self = (Main*)a0;
 c = self->counter;
 self->counter = c + 1;
 for (int i = self->count - 1; i >= 0; --i) { Object_vptr_0* item = self->items[i]; if (item) item->slot2(arg); }
 self->cleanup();
 for (k = 0; k < arg->nodeCount; ++k) {
  Node* node = arg->nodes[k];
  for (int m = node->innerCount - 1; m >= 0; --m) {
   Object_vptr_0* in = node->inners[m];
   if (in) {
    int idx = k * 4;
    in->slot1(*(Node**)((char*)arg->nodes + idx));
   }
  }
  node->cleanup();
 }
 if (--self->counter == 0 && self->f78 != 0 && self->f84 == 0) fn_802EFE70(self);
}