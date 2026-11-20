#pragma force_active on
#include <mt/mt_common.h>
#include <nw4r/math/math_arithmetic.h>
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
union U { unsigned long long r; Vec2 v; };
struct Acc;
class PosMod {
public:
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual Vec3 getPos();
};
class WorkMod {
public:
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual unsigned int getInt(unsigned int);
 virtual void v5();
 virtual void v6();
 virtual void v7();
 virtual void v8();
 virtual void v9();
 virtual void v10();
 virtual void v11();
 virtual float getFloat(unsigned int);
};
struct Mods { char pad[0xc]; PosMod* pos; char pad2[0x54]; WorkMod* work; };
struct Acc { char pad[0xd8]; Mods* mods; };
class Obj {
public:
 virtual void v0();
 virtual void update(Acc*);
 virtual unsigned long long get();
 int pad0;
 Vec2 a, b, c, pad, d;
};
extern "C" {
extern const float lbl_113_rodata_88[];
Vec2* fn_113_C30C(Vec2*, float, float);
unsigned long long fn_113_BFB0(const Vec2*, const Vec2*);
float fn_113_BF74(const Vec2*);
void fn_113_BC00(Vec2*, const Vec2*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Acc*, unsigned long, unsigned long);
void fn_8003DBA8(Vec2*);
void fn_113_1E5B8(Vec2*, float);
unsigned long long fn_113_1E58C(Vec2*);
}

extern "C" void fn_113_2172C(void*, Obj* obj, Acc* acc) {
 Vec2 pos;
 Vec2 tgt;
 U diff;
 Vec2 v40;
 U s;
 U r;
 const float* c = lbl_113_rodata_88;
 PosMod* pm = acc->mods->pos;
 fn_113_C30C(&pos, pm->getPos().x, pm->getPos().y);
 WorkMod* w = acc->mods->work;
 float ty = w->getFloat(0x11000005);
 fn_113_C30C(&tgt, w->getFloat(0x11000004), ty);
 float var = c[4];
 if (!(acc->mods->work->getInt(0x10000011) & 0x10)) {
  var *= c[3];
 }
 tgt.x += var;
 r.r = fn_113_BFB0(&tgt, &pos);
 diff = r;
 float len = (float)(double)nw4r::math::FAbs(diff.v.x);
 if (c[2] == len) {
  Vec2 z; z.x = c[2]; z.y = c[2];
  fn_113_BC00(&obj->a, &z);
  return;
 }
 float f1 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfa5, 0);
 if (len >= f1) {
  Vec2 v; v.x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfc7, 0); v.y = c[2];
  fn_113_BC00(&obj->c, &v);
 } else {
  Vec2 v; v.x = (len / f1) * getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfc7, 0); v.y = c[2];
  fn_113_BC00(&obj->c, &v);
 }
 v40.x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xfc6, 0);
 v40.y = c[2];
 if (diff.v.x < c[2]) {
  U t;
  t.r = fn_113_1E58C(&v40);
  v40 = t.v;
 }
 fn_113_BC00(&obj->b, &v40);
 obj->update(acc);
 U s0;
 s0.r = obj->get();
 s = s0;
 if (fn_113_BF74(&s.v) > len * len) {
  fn_8003DBA8(&s.v);
  fn_113_1E5B8(&s.v, len);
  fn_113_BC00(&obj->a, &s.v);
 }
}
