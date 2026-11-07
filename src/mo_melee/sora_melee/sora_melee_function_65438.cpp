#include <types.h>
#pragma force_active on
struct Vec { float x, y, z; Vec() {} Vec(const Vec& v) : x(v.x), y(v.y), z(v.z) {} };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual Vec slot4(); virtual void slot5(const Vec&); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual u32 slot9(int); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual float slot22();
};
struct Pad8 { int a, b; };
class Model : public Pad8 {
public:
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
 virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
 virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
 virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
 virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
 virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
 virtual Vec s36(int, int);
};
struct Modules { char pad[4]; Model* model; int pad8; Object_vptr_0* posture; char pad10[0x44]; Object_vptr_0* other; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Self { char pad[0x10]; Access* access; int pad14; int node; float offset; };
extern "C" void fn_27_65438(Self* self) {
 if (self->access->modules->other->slot9(0) == 1) {
  Vec pos = self->access->modules->posture->slot4();
  Vec node = self->access->modules->model->s36(self->node, 0);
  pos.x = node.x;
  pos.y = node.y - self->offset * self->access->modules->posture->slot22();
  self->access->modules->posture->slot5(pos);
 }
}