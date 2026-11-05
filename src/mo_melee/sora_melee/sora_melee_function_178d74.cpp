#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <types.h>
#pragma force_active on
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" unsigned char lbl_27_data_2E5F8[8];
extern "C" unsigned char lbl_27_data_CDF8[8];
struct Kinetic { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void* get(int); };
struct Energy { virtual void v0(); virtual void v1(); virtual u64 getVal(); };
struct Posture { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual float getLr(); };
union Pair { u64 bits; float f[2]; };
extern "C" void fn_27_178D74(void*, soModuleAccesser* accesser) {
 Kinetic* kin=(Kinetic*)&accesser->getKineticModule();
 Energy* e=(Energy*)__dynamic_cast(kin->get(3),0,lbl_27_data_2E5F8,lbl_27_data_CDF8,1);
 Pair b,a;
 a.bits=e->getVal();
 b=a;
 Posture* post=(Posture*)&accesser->getPostureModule();
 float lr=post->getLr();
 float neg=-lr;
 float c=soValueAccesser::getConstantFloat(accesser,0xcc5,0);
 b.f[0]=b.f[0]+c*neg;
 *(float*)((char*)e+8)=b.f[0];
 *(float*)((char*)e+12)=b.f[1];
}