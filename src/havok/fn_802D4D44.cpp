#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual unsigned int slot2();
 virtual unsigned int slot3(unsigned int);
};
extern "C" int fn_802D4D44(Object_vptr_0* self) {
 int count = 0;
 unsigned int value = self->slot2();
 while (value != 0xffffffffU) {
  ++count;
  value = self->slot3(value);
 }
 return count;
}