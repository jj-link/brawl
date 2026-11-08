#pragma force_active on
#pragma use_lmw_stmw on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual int slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual int slot15(int);
 char pad[12];
 Object_vptr_0* field_10;
};
struct Node {
 Object_vptr_0* obj;
 int field_4;
 int pad8;
 Node* next;
 char pad10[12];
 int field_1C;
};
struct Table { char pad[0x10C]; unsigned flags[1]; };
inline int resolve(Table** table, Node* node) {
 if ((unsigned)(node->field_4 + 0x10000) == 0xffffU) {
  while (node->next) node = node->next;
  return node->field_1C;
 }
 Node* cur = node->next;
 do {
  int index = cur->obj->slot2();
  unsigned flags = (*table)->flags[index];
  if ((signed char)((flags >> 2) & 1)) return cur->obj->slot15(node->field_4);
  if ((signed char)((flags >> 3) & 1)) return cur->obj->field_10->slot15(node->field_4);
  if ((signed char)((flags >> 11) & 1)) {
   while (node->next) node = node->next;
   return node->field_1C;
  }
  cur = cur->next;
 } while (cur);
 return 0;
}
extern "C" void fn_802CD1D0(void*, int, int);
extern "C" void fn_802CD254(void* self, Table** table, Node* node, void*, Object_vptr_0* obj, int key) {
 int saved = obj->slot15(key);
 fn_802CD1D0(self, resolve(table, node), saved);
}
