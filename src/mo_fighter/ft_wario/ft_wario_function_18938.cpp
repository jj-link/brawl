#pragma force_active on
struct Vec3 { float x, y, z; };
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void fn_110_12B14(int,int,Vec3*,Vec3*,float,Vec3*,Vec3*,unsigned short,int);
 virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual int slot17();
};
struct Modules { char pad0[8]; Object_vptr_0* a; char pad1[0x7C]; Object_vptr_0* b; };
struct Accesser { char pad[8]; void* owner; char pad2[0xCC]; Modules* modules; };
extern "C" {
extern const float lbl_110_rodata_158[3];
Vec3* fn_110_CC98(Vec3*, float, float, float);
void fn_110_18938(void* arg1, Accesser* accesser) {
 Vec3* p2;
 Vec3* p1;
 Vec3* p0;
 const float* k = lbl_110_rodata_158;
 Object_vptr_0* b;
 Vec3 v3, v2, v1, v0;
 Object_vptr_0* a = accesser->modules->a;
 if (a->slot17() != 0) {
  b = accesser->modules->b;
  p0 = fn_110_CC98(&v0, k[1], k[1], k[1]);
  p1 = fn_110_CC98(&v1, k[1], k[1], k[1]);
  p2 = fn_110_CC98(&v2, k[1], k[2], k[1]);
  Vec3* p3 = fn_110_CC98(&v3, k[1], k[1], k[1]);
  b->fn_110_12B14(10, 9, p3, p2, k[0], p1, p0, 0, 0);
 }
}
}
