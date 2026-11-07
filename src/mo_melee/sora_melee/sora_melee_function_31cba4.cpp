#pragma force_active on
#pragma fp_contract off
#include <mt/mt_vector.h>

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
 virtual float slot9();
 virtual void slot10();
 virtual void slot11();
 virtual float slot12(unsigned int);
 virtual void slot13(unsigned int, float);
};
class Kinetic {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual unsigned long long slot13(short*);
};
struct Params { char pad[0xac]; float max, decel, accel, scale; };
struct Owner { char pad[0x4870]; Params* params; };
struct Modules { char pad0[0xc]; Object_vptr_0* posture; char pad10[0x54]; Object_vptr_0* work; char pad68[0x14]; Kinetic* kinetic; };
struct Access { char pad0[8]; void* owner; char padc[0xcc]; Modules* modules; };
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_48E80[], lbl_27_data_248[];
extern float lbl_27_rodata_74F0[];
void fn_27_31CBA4(void*, Access* self) {
 Params* params = ((Owner*)__dynamic_cast(self->owner, 0x3c, lbl_27_data_48E80, lbl_27_data_248, 1))->params;
 Object_vptr_0* posture = self->modules->posture;
 Object_vptr_0* work = self->modules->work;
 Kinetic* kinetic = self->modules->kinetic;
 float facing = posture->slot9();
 float speed = work->slot12(0x21000000);
 float other = work->slot12(0x21000005);
 float base = work->slot12(0x11000002);
 short flag = -1;
 union Pair { unsigned long long raw; struct { float x, y; } v; };
 Pair p;
 p.raw = kinetic->slot13(&flag);
 float delta = facing * (p.v.x - base);
 if (lbl_27_rodata_74F0[0] == delta) {
  if (speed > lbl_27_rodata_74F0[0]) {
   speed -= params->decel;
   if (speed < lbl_27_rodata_74F0[0]) speed = lbl_27_rodata_74F0[0];
  } else if (speed < lbl_27_rodata_74F0[0]) {
   speed += params->decel;
   if (speed > lbl_27_rodata_74F0[0]) speed = lbl_27_rodata_74F0[0];
  }
 } else {
  speed -= delta * params->accel;
  if (speed > params->max) speed = params->max;
  else if (speed < -params->max) speed = -params->max;
 }
 float result = params->scale * (speed / params->max);
 work->slot13(0x21000000, speed);
 work->slot13(0x21000002, result);
 work->slot13(0x21000005, other);
}
}