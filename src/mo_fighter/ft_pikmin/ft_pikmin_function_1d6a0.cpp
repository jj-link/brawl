#include <so/so_module_accesser.h>
#pragma force_active on
struct Vec2 { float x, y; };
union Pair { unsigned long long raw; Vec2 v; };
#pragma pack(push, 4)
struct Temps { bool a, b; Pair p2, q2; Vec2 v2; Pair p1, q1; Vec2 v1; Pair p0; };
#pragma pack(pop)
class Class_6B48 {
public:
 virtual void fn_113_10FB8(); virtual void fn_113_10E80(); virtual unsigned long long fn_113_CBA8();
 virtual void fn_113_CBA4(); virtual void fn_113_CBA0(); virtual void fn_113_CB9C(); virtual void fn_113_CB98(); virtual void fn_113_CB94(); virtual void fn_113_CB90(); virtual void fn_113_CB88();
 bool isActive() const { return active != 0; }
 unsigned char pad; unsigned char active : 1; char pad2[2]; Vec2 value;
};
struct Obj { char pad[0x10]; Class_6B48 a; char pad2[0x30]; Class_6B48 b; };
extern "C" Vec2* fn_113_C30C(Vec2*, float, float);
extern "C" void fn_113_BC00(Vec2*, const Vec2*);
extern "C" void fn_113_1D6A0(Vec2* input, Obj* obj, soModuleAccesser* accesser) {
 float x = input->x * accesser->m_enumerationStart->m_postureModule->getLr();
 float y = input->y;
 Temps t;
 t.b = false;
 Class_6B48* a = &obj->a;
 t.a = false;
 Class_6B48* b = &obj->b;
 if ((unsigned int)b->isActive() == 1) {
  t.p0.raw = b->fn_113_CBA8(); b->value.x = y + t.p0.v.y;
 } else if ((unsigned int)a->isActive() == 1) {
  t.p1.raw = a->fn_113_CBA8(); t.q1.raw = a->fn_113_CBA8();
  fn_113_C30C(&t.v1, t.q1.v.x, y + t.p1.v.y); fn_113_BC00(&a->value, &t.v1);
 }
 if ((unsigned int)a->isActive() == 1) {
  t.p2.raw = a->fn_113_CBA8(); t.q2.raw = a->fn_113_CBA8();
  fn_113_C30C(&t.v2, x + t.q2.v.x, t.p2.v.y); fn_113_BC00(&a->value, &t.v2);
 }
}