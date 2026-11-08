#include <mt/mt_vector.h>
#pragma force_active on
extern "C" { extern const unsigned char lbl_110_data_60DC[],lbl_110_data_6EB0[],lbl_110_data_168C[],lbl_110_data_5EF0[],lbl_110_data_212C[]; void* __dynamic_cast(void*,long,const void*,const void*,short); void fn_110_B860(void*,const void*); float fn_110_1526C(const Vec2f&); }
struct Accesser{unsigned char pad0[8];void* stageObject;unsigned char pad_c[0xcc];void* enumeration;};
struct Kinetic{virtual void k0();virtual void k1();virtual void k2();virtual void k3();virtual void k4();virtual void k5();virtual void* getEnergy(int);virtual void k7();virtual void k8();virtual void k9();virtual void k10();virtual void k11();virtual void k12();virtual void k13();virtual void k14();virtual void k15();virtual void k16();virtual void k17();virtual void k18();virtual void k19();virtual void k20();virtual void f23(int,void*);};
struct Work{virtual void w0();virtual void w1();virtual void w2();virtual void w3();virtual int f6(unsigned long);virtual void w5();virtual void w6();virtual void w7();virtual void w8();virtual void w9();virtual void w10();virtual void w11();virtual float f14(unsigned long);virtual void w13();virtual void w14();virtual void w15();virtual void w16();virtual int f19(unsigned long);virtual void f20(unsigned long);};
struct Status{virtual void s0();virtual void s1();virtual void s2();virtual void f5(int,void*);};
struct Energy{virtual void e0();virtual void e1();virtual Vec2f getSpeed();};
struct Param{float pad0[5];float f14;float pad18[12];float f48;float pad4c[7];float f68;float f6c;int f70;};
struct Weapon{unsigned char pad[0x2980];Param* param;};
struct EnumLayout{unsigned char pad0[0x64];Work* work;unsigned char pad68[8];Status* status;unsigned char pad74[8];Kinetic* kinetic;};
extern "C" void fn_110_17CF4(void*,Accesser* accesser) {
 EnumLayout* en=(EnumLayout*)accesser->enumeration;Work* work=en->work;Kinetic* kinetic=en->kinetic;Status* status=en->status;
 Energy* e0=(Energy*)__dynamic_cast(kinetic->getEnergy(0),0,lbl_110_data_60DC,lbl_110_data_168C,1);
 Param* param;Energy* e1=(Energy*)__dynamic_cast(kinetic->getEnergy(1),0,lbl_110_data_6EB0,lbl_110_data_168C,1);
 param=((Weapon*)__dynamic_cast(accesser->stageObject,0x3c,lbl_110_data_5EF0,lbl_110_data_212C,1))->param;
 float a=work->f14(0x21000002);float b=work->f14(0x21000003);
 if(work->f19(0x22000005)==0){status->f5(2,accesser);return;}
 Vec2f v;
 if(a-b>param->f48){v=e0->getSpeed();v.m_x*=param->f68;fn_110_B860((char*)e0+8,&v);v=e1->getSpeed();v.m_y+=param->f6c;*(float*)((char*)e1+8)=v.m_y;((unsigned char*)e1)[5]|=0x80;kinetic->f23(0x21,accesser);((EnumLayout*)accesser->enumeration)->work->f20(0x22000008);}
 else {kinetic=0;float len=fn_110_1526C(e0->getSpeed());if(len<param->f14){long p=work->f6(0x20000002);if(p>=param->f70)kinetic=(Kinetic*)1;}if(kinetic!=0)status->f5(0xd,accesser);}
}