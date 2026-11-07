#pragma force_active on
#pragma fp_contract off
#include <nw4r/math/math_arithmetic.h>
typedef unsigned long long u64;
struct Vec2 { float x, y; };
class Object_vptr_0 {
public:
 virtual void slot0();
 virtual void slot1();
 virtual u64 slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5(int, unsigned long);
 virtual void* slot6(int);
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13(unsigned long, float);
};
struct Modules { char pad[0x64]; Object_vptr_0* work; char pad1[0x14]; Object_vptr_0* energy; };
struct Access { char pad[8]; void* object; char pad1[0xcc]; Modules* modules; };
struct Self { char pad[0x60]; Access* access; };
struct Inner2 { char pad[8]; int limit; };
struct Inner1 { char pad[0x34]; Inner2* inner2; };
struct Inner0 { char pad[0xbc]; Inner1* inner1; };
extern "C" {
extern char lbl_27_data_457C0[], lbl_27_data_CDF8[], lbl_27_data_7DFD8[], lbl_27_data_248[];
extern const float lbl_27_rodata_6448[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_1DAE14(void*);
float rsqrtf__Ff(float);
double atan2(double, double);
int fn_27_2EDF98(void* arg0) {
 const float* k = lbl_27_rodata_6448;
 Access* access;
 Object_vptr_0* work;
 int ret = fn_27_1DAE14(arg0);
 access = ((Self*)arg0)->access;
 Modules* modules = access->modules;
 Object_vptr_0* energy = modules->energy;
 work = modules->work;
 Object_vptr_0* dst = (Object_vptr_0*)__dynamic_cast(energy->slot6(0), 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);
 u64 bits = dst->slot2();
 Vec2 v = *(Vec2*)&bits;
 float sum = v.x*v.x + v.y*v.y;
 float mag;
 if ((float)(double)nw4r::math::FAbs(sum) <= k[7]) mag = k[1];
 else mag = sum * rsqrtf__Ff(sum);
 if (mag > k[8]) {
  double x = v.x;
  double y = v.y;
  work->slot13(0x11000001, -(float)atan2(y, x));
 }
 Inner0* in0 = (Inner0*)__dynamic_cast(access->object, 0x3c, lbl_27_data_7DFD8, lbl_27_data_248, 1);
 work->slot5(in0->inner1->inner2->limit + 1, 0x10000006);
 return ret;
}
}