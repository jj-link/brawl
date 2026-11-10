#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual int slot10();
};
struct Obj {
 char pad[8];
 Object_vptr_0* object;
 char pad2[4];
 int start;
 int end;
};
extern "C" int fn_80281330(Obj* self) {
 int value = self->object->slot10();
 if (value >= 0)
  return value - (self->end - self->start);
 return -1;
}