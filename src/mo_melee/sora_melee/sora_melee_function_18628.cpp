#include <types.h>
#include <nw4r/math/math_types.h>
#pragma force_active on
#pragma scheduling on
#pragma schedule_prologue on
#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale

inline nw4r::math::VEC3 ScaleVector(const nw4r::math::VEC3& v, float scale) {
    nw4r::math::VEC3 result;
    LocalScale((const Vec*)&v, (Vec*)&result, scale);
    return result;
}
}
#pragma force_active on
struct PairInt { int x,y; };
struct Src { int a; PairInt b; int c; PairInt d; int e; PairInt f,g,h,i,j,k; };
class Model {
public:
 char pad[8];
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4();
 virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
 virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14();
 virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19();
 virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24();
 virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29();
 virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33();
 virtual u32 convertIndex(u32);
 virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual void f39();
 virtual void f40(); virtual void f41(); virtual void f42(); virtual void f43(); virtual void f44();
 virtual void f45(); virtual void f46(); virtual void f47();
 virtual u32 getHandle();
 virtual void f49(); virtual void f50(); virtual void f51(); virtual void f52(); virtual void f53();
 virtual float getScale();
};
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4();
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual Src& slot12(Src&, u32); virtual void slot13(); virtual void slot14();
 virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual float slot22();
};
struct Pair { char pad0[4]; Model* model; char pad8[4]; Object_vptr_0* holder; };
struct Outer { char pad[0xD8]; Pair* pair; };
struct Obj { char pad[0x6C]; Object_vptr_0* getter; char pad2[0xF8]; Outer* outer; };
struct IntVec { int x,y,z; };
extern "C" void fn_8019589C(Src*, Vec*);
extern const float lbl_27_rodata_344;
extern "C" nw4r::math::VEC3 fn_27_18628(const Obj* self) {
 Model* model2;
 Object_vptr_0* getter = self->getter;
 if (getter != 0) {
  Model* model = self->outer->pair->model;
  u32 slot = model->convertIndex(model->getHandle());
  if (slot != 0xFFFFFFFF) {
   Src tmp;
   Src* p = &self->getter->slot12(tmp, slot);
   if (p != &tmp) { tmp = *p; p = &tmp; }
   nw4r::math::VEC3 v;
   fn_8019589C(p, (Vec*)&v);
   Pair* pair = self->outer->pair;
   model2 = pair->model;
   float s = pair->holder->slot22();
   float scale = model2->getScale();
   v = ScaleVector(v, scale * s);
   return v;
  }
 }
 return nw4r::math::VEC3(lbl_27_rodata_344, lbl_27_rodata_344, lbl_27_rodata_344);
}