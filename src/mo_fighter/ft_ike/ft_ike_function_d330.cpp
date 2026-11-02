#pragma force_active on
struct Vec2 { float x,y; Vec2() {} Vec2(float a,float b):x(a),y(b) {} };
struct Kinetic {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void* getEnergy(int);
virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
virtual Vec2 speed(const short&);
};
struct Status {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual int kind();
};
struct Situation {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual int kind();
};
struct Energy {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void reset(int,const Vec2*,const float*,void*);
};
struct Work {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void set(int,int);
virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
virtual float getFloat(int); virtual void setFloat(float,int);
};

extern "C" {
extern const char lbl_119_data_5C14[],lbl_119_data_5CF4[],lbl_119_data_1374[];
extern const float lbl_119_rodata_48;
extern char* g_ftManager;
void* __dynamic_cast(void*,long,const void*,const void*,short);
float* fn_119_8F00(float*,float,float,float);
void fn_119_D73C(void*,const Vec2*);
void fn_27_89DAC(int,void*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*,unsigned int,unsigned int);
}
template<class T> inline T* module(void* a,int offset) {return *(T**)(*(char**)((char*)a+0xd8)+offset);}
inline float constant(void* a,unsigned int id) {return getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(a,id,0);}
inline const Vec2* address(const Vec2& v) {return &v;}
inline void copySpeed(Vec2& out,const Vec2& v) { __memcpy(&out,&v,8); }
extern "C" void fn_119_D330(void*,void* a) {
Energy* stop=(Energy*)__dynamic_cast(module<Kinetic>(a,0x7c)->getEnergy(3),0,lbl_119_data_5C14,lbl_119_data_1374,1);
Energy* gravity=(Energy*)__dynamic_cast(module<Kinetic>(a,0x7c)->getEnergy(1),0,lbl_119_data_5CF4,lbl_119_data_1374,1);
short mask=1;
Vec2 g,d,v,v2;
Vec2 summed; copySpeed(summed,module<Kinetic>(a,0x7c)->speed(mask));
float horizontal=summed.x;
switch(module<Status>(a,0x70)->kind()) {
case 0x115:
if(module<Situation>(a,0x14)->kind()==0) {
float rot[3];
stop->reset(0,address(Vec2(summed.x,lbl_119_rodata_48)),fn_119_8F00(rot,lbl_119_rodata_48,lbl_119_rodata_48,lbl_119_rodata_48),a);
((unsigned char*)stop)[5]|=0x80;
fn_27_89DAC(1,a); fn_27_89DAC(2,a);
module<Work>(a,0x64)->set(0,0x20000000);
} else {
horizontal*=constant(a,0xfb5);
float zero=lbl_119_rodata_48;
float rot[3];
stop->reset(6,address(Vec2(horizontal,zero)),fn_119_8F00(rot,zero,zero,zero),a);
fn_119_D73C(stop,address(Vec2(constant(a,0xfb6),lbl_119_rodata_48)));
((unsigned char*)stop)[5]|=0x80;
float grot[3];
gravity->reset(0,address(Vec2(lbl_119_rodata_48,zero)),fn_119_8F00(grot,lbl_119_rodata_48,lbl_119_rodata_48,lbl_119_rodata_48),a);
*(float*)((char*)gravity+0x10)=-constant(a,0xfb7);
*(float*)((char*)gravity+0x14)=constant(a,0xfb8);
((unsigned char*)gravity)[5]|=0x80;
fn_27_89DAC(2,a);
module<Work>(a,0x64)->set(2,0x20000000);
}
break;
case 0x121:
{
float value=module<Work>(a,0x64)->getFloat(0x21000004);
float scale=constant(a,0xfb9);
float maximum=constant(a,0xfbc);
if((unsigned char)g_ftManager[0x68]==1) {
scale=constant(a,0xfba); maximum=constant(a,0xfbd);
}
scale=value*scale;
if(scale<constant(a,0xfbb)) scale=constant(a,0xfbb);
if(scale>maximum) scale=maximum;
module<Work>(a,0x64)->setFloat(scale,0x21000004);
break;
}
}
}
