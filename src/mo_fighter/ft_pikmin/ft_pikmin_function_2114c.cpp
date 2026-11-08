#pragma force_active on
#include <mt/mt_common.h>
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
union U { unsigned long long r; Vec2 v; };
struct Acc;
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1(Acc*);
 virtual unsigned long long slot2();
 virtual void slot3();
 virtual Vec3 slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual float slot9();
 virtual void slot10();
 virtual void slot11();
 virtual float slot12(unsigned int);
 int pad;
 Vec2 value;
 char pad2[8];
 Vec2 other;
};
struct Mods { char pad[0xc]; Object_vptr_0* pos; char pad2[0x54]; Object_vptr_0* work; };
struct Acc { char pad[0xd8]; Mods* mods; };
extern "C" {
extern const float lbl_113_rodata_90;
extern const float lbl_113_rodata_B8;
Vec2* fn_113_C30C(Vec2*, float, float);
unsigned long long fn_113_BFB0(const Vec2*, const Vec2*);
float fn_113_BF74(const Vec2*);
void fn_113_BC00(Vec2*, const Vec2*);
void fn_8003DBA8(Vec2*);
void fn_113_1E5B8(Vec2*, float);
}
extern "C" void fn_113_2114C(void*, Object_vptr_0* obj, Acc* acc) {
 Vec2 pos;
 Vec2 tgt;
 U diff;
 U nl;
 Object_vptr_0* pm = acc->mods->pos;
 fn_113_C30C(&pos, pm->slot4().x, pm->slot4().y);
 Object_vptr_0* w = acc->mods->work;
 float ty = w->slot12(0x11000005);
 U r;
 fn_113_C30C(&tgt, w->slot12(0x11000004), ty);
 r.r = fn_113_BFB0(&tgt, &pos);
 diff = r;
 float len = fn_113_BF74(&diff.v);
 if (lbl_113_rodata_90 == len) {
  Vec2 z; z.x = lbl_113_rodata_90; z.y = lbl_113_rodata_90;
  fn_113_BC00(&obj->value, &z);
 } else if (diff.v.x * acc->mods->pos->slot9() < lbl_113_rodata_90) {
  Vec2 z; z.x = lbl_113_rodata_90; z.y = lbl_113_rodata_90;
  fn_113_BC00(&obj->value, &z);
 } else {
  obj->slot1(acc);
  if (fn_113_BF74(&obj->other) > len) {
   U s;
   s.r = obj->slot2();
   nl = s;
   fn_8003DBA8(&nl.v);
   fn_113_1E5B8(&nl.v, lbl_113_rodata_B8 * mtSqrtf(len));
   fn_113_BC00(&obj->value, &nl.v);
  }
 }
}