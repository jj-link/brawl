#include <mt/mt_vector.h>
#pragma force_active on
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual int slot4(unsigned int);
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8(unsigned int);
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual bool slot17(unsigned int);
};
struct Modules { char pad[0x64]; Object_vptr_0* work; };
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Self { char pad[5]; unsigned char flag : 1; unsigned char other : 7; char pad2[2]; Vec2f vector; };
extern "C" float lbl_27_rodata_78A8;
extern "C" void fn_27_348450(Self* self, void*, Accesser* accesser) {
 if (!accesser->modules->work->slot17(0x22000010)) {
  self->vector = Vec2f(lbl_27_rodata_78A8, lbl_27_rodata_78A8);
  self->flag = 0;
 } else {
  accesser->modules->work->slot8(0x20000002);
  if (accesser->modules->work->slot4(0x20000002) < 0) {
   self->vector = Vec2f(lbl_27_rodata_78A8, lbl_27_rodata_78A8);
  }
 }
}