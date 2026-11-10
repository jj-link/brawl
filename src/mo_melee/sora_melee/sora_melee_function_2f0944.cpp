#pragma force_active on
#pragma fp_contract off
#include <nw4r/math/math_arithmetic.h>
#include <mt/mt_common.h>
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_27_2EFED4(void*);
void fn_8003DBA8(void*);
extern char lbl_27_data_248[], lbl_27_data_457C0[], lbl_27_data_7E6B0[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_64B0[];
}
typedef unsigned long long u64;
struct Pr { int a; int b; };
inline Pr unpack(const u64& bits) { Pr result = *(const Pr*)&bits; return result; }
inline Pr scale(const Pr& vec, float k) {
 Pr sc; *(float*)&sc.a = *(const float*)&vec.a * k;
 *(float*)&sc.b = *(const float*)&vec.b * k; return sc;
}
class Object_vptr_0 {
public:
 virtual void slot0(); virtual void slot1(); virtual u64 slot2();
 virtual void slot3(); virtual int slot4(unsigned int); virtual void slot5();
 virtual void* slot6(int); virtual void slot7(unsigned int);
 virtual void slot8(); virtual void slot9(void*); virtual void slot10();
 virtual void slot11(); virtual void slot12(); virtual void slot13();
 virtual void slot14(); virtual void slot15(); virtual int slot16();
};
extern "C" void fn_27_2F0944(void* unused, char* a) {
 const float* k = lbl_27_rodata_64B0;
 Object_vptr_0* o0 = *(Object_vptr_0**)(*(char**)(a + 0xd8) + 0x70);
 int r31 = o0->slot16();
 void* dc = __dynamic_cast(*(void**)(a + 8), 0x3c, lbl_27_data_7E6B0, lbl_27_data_248, 1);
 char* r29 = *(char**)((char*)fn_27_2EFED4(dc) + 0x34);
 switch (r31) { case 0: break; default: return; }
 r31 = (*(Object_vptr_0**)(*(char**)(a + 0xd8) + 0x64))->slot4(0x10000006);
 Object_vptr_0* oc = *(Object_vptr_0**)(*(char**)(a + 0xd8) + 0xc);
 oc->slot9(*(void**)(a + 0xd8));
 if (r31 <= *(int*)(r29 + 8)) {
  if (r31 == *(int*)(r29 + 8)) {
   Object_vptr_0* o7c = *(Object_vptr_0**)(*(char**)(a + 0xd8) + 0x7c);
   void* t = o7c->slot6(0);
   void* dc2 = __dynamic_cast(t, 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);
   Pr vec;
   u64 bits = ((Object_vptr_0*)dc2)->slot2();
   vec = *(const Pr*)&bits;
   float sum = (*(float*)&vec.a) * (*(float*)&vec.a) + (*(float*)&vec.b) * (*(float*)&vec.b);
   float len;
   if ((float)(double)nw4r::math::FAbs(sum) <= k[1]) len = k[0];
   else len = sum * rsqrtf(sum);
   if (len > k[2]) {
    fn_8003DBA8(&vec);
    float kk = *(float*)(r29 + 0x10);
    Pr out = scale(vec, kk);
    *(float*)((char*)dc2 + 0x10) = *(float*)&out.a;
    *(float*)((char*)dc2 + 0x14) = *(float*)&out.b;
   }
  }
  Object_vptr_0* o9 = *(Object_vptr_0**)(*(char**)(a + 0xd8) + 0x64);
  o9->slot7(0x10000006);
 }
}