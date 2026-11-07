#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4(float, float, int, float, int);
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12(int, void*, int);
};
struct Entry { char bytes[0x20]; };
struct List { Entry* entries; int count; };
struct Data { char pad[0x30]; List* list; };
extern int lbl_41_data_405C;
extern "C" void fn_41_31308(char* self, float a, float b, int arg, float c) {
 Object_vptr_0* obj = *(Object_vptr_0**)(*(char**)(*(char**)(self + 0x6c) + 0xd8) + 0x20);
 if ((*(Data**)(self + 0x2184))->list) {
  obj->slot12(0, (*(Data**)(self + 0x2184))->list->entries, 0);
  if ((*(Data**)(self + 0x2184))->list->count >= 2)
   obj->slot12(1, (*(Data**)(self + 0x2184))->list->entries + 1, 0);
  else
   obj->slot12(1, &lbl_41_data_405C, 0);
 } else {
  obj->slot12(0, &lbl_41_data_405C, 0);
  obj->slot12(1, &lbl_41_data_405C, 0);
 }
 obj->slot4(a, b, arg, c, 0);
}