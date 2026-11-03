#include <types.h>
#pragma force_active on
struct Vec { float x, y, z; Vec() {} Vec(const Vec& v) : x(v.x), y(v.y), z(v.z) {} };
class soPostureModuleImpl {
public:
 virtual void isNull();
 virtual ~soPostureModuleImpl();
 virtual void fn_27_2362C();
 virtual void fn_27_236B0();
 virtual Vec fn_27_25088();
 virtual void fn_27_23E84(const Vec&);
 virtual void fn_27_25184();
 virtual void fn_27_2370C();
 virtual void fn_27_23728();
 virtual void fn_27_23E28();
 virtual void fn_27_23CC0();
 virtual void fn_27_25068();
 virtual void fn_27_23A9C();
 virtual void fn_27_23B18();
 virtual void fn_27_250FC();
 virtual void fn_27_250A4();
 virtual void fn_27_23BF8();
 virtual void fn_27_251B8();
 virtual void fn_27_251B0();
 virtual void fn_27_23C14();
 virtual void fn_27_25154();
 virtual void fn_27_2517C();
 virtual float fn_27_23744();
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
struct Modules { char pad[4]; Model* model; int pad8; soPostureModuleImpl* posture; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Self { char pad[0x10]; Access* access; char pad14[8]; int node; float offset; char pad24[9]; u8 flag1; char pad2e; u8 flag2; };
extern "C" void fn_27_66BDC(Self* self) {
 if (self->flag1 == 1 && self->flag2 == 1) {
  Vec pos = self->access->modules->posture->fn_27_25088();
  Vec node = self->access->modules->model->s36(self->node, 0);
  pos.x = node.x;
  pos.y = node.y - self->offset * self->access->modules->posture->fn_27_23744();
  self->access->modules->posture->fn_27_23E84(pos);
 }
}