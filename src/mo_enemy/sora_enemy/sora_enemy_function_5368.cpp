#pragma always_inline on
#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
extern "C" {
void fn_27_4570(void*, unsigned int);
void fn_41_17DA8(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_41_data_644[], lbl_41_data_6A8[];
extern const float lbl_41_rodata_8, lbl_41_rodata_28;
}
struct Pair { float a,b; Pair& operator=(const Pair& p) { ((u32*)this)[0] = ((const u32*)&p)[0]; ((u32*)this)[1] = ((const u32*)&p)[1]; return *this; } };
class Object_vptr_0 {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual Vec3f slot4(); virtual void slot5(Vec3f*);
virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual Pair slot13(short*);
};
extern "C" void fn_41_5368(char* self, unsigned int arg1) {
const Vec3f& v = (*(Object_vptr_0**)(*(char**)(self+0x1B4)+0xC))->slot4();
fn_27_4570(self,arg1);
if(arg1==1) { void* p=__dynamic_cast(*(void**)(*(char**)(self+0x1B4)+0x7C),0,lbl_41_data_644,lbl_41_data_6A8,1); fn_41_17DA8(p,-1); }
Vec3f w = (*(Object_vptr_0**)(*(char**)(self+0x1B4)+0xC))->slot4();
Pair pr;
Pair pr2;
if(lbl_41_rodata_8 != *(float*)(self+0xD0)) {
short s=-1;
Pair t=(*(Object_vptr_0**)(*(char**)(self+0x1B4)+0x7C))->slot13(&s);
pr=t;
float a=(float)(double)nw4r::math::FAbs(*(float*)(self+0xD0)-v.m_x);
float b=(float)(double)nw4r::math::FAbs(pr.a);
if(lbl_41_rodata_28+b>=a) { w.m_x=*(float*)(self+0xD0); (*(Object_vptr_0**)(*(char**)(self+0x1B4)+0xC))->slot5(&w); }
}
if(lbl_41_rodata_8 != *(float*)(self+0xD4)) {
short s2=-1;
Pair t2=(*(Object_vptr_0**)(*(char**)(self+0x1B4)+0x7C))->slot13(&s2);
pr2=t2;
float a2=(float)(double)nw4r::math::FAbs(*(float*)(self+0xD4)-v.m_y);
float b2=(float)(double)nw4r::math::FAbs(pr2.b);
if(lbl_41_rodata_28+b2>=a2) { w.m_y=*(float*)(self+0xD4); (*(Object_vptr_0**)(*(char**)(self+0x1B4)+0xC))->slot5(&w); }
}
}