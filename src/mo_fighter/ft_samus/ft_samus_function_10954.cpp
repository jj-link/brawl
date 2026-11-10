#include <types.h>
#include <so/so_value_accesser.h>
#include <ft/ft_common_data_accesser.h>
#pragma force_active on
struct Vec2 { float x,y; Vec2() {} Vec2(float a,float b):x(a),y(b){} };
struct Vec3 {float x,y,z;};
class Energy {public:
virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
virtual void reset(int,Vec2*,Vec3*,void*);
};
class Kinetic {public:
virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
virtual Energy* getEnergy(int);
virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
virtual Vec2 getSum(const short*);
};
class Work {public:
virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
virtual bool isFlag(unsigned int); virtual void onFlag(unsigned int); virtual void offFlag(unsigned int);
virtual void v21(); virtual void v22(); virtual void clearAll(int);
};
class Status {public:
virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual int getStatusKind();
};
class Situation {public: virtual void v1(); virtual void v2(); virtual void v3(); virtual int getKind();};
struct Modules {char pad0[0x14]; Situation* situation; char pad1[0x4c]; Work* work; char pad2[8]; Status* status; char pad3[8]; Kinetic* kinetic;};
struct Accesser {char pad[0xd8]; Modules* modules;};
extern "C" {
extern const char lbl_94_data_9804[],lbl_94_data_98E4[],lbl_94_data_4570[];
extern const float lbl_94_rodata_40;
void* __dynamic_cast(void*,long,const void*,const void*,short);
void fn_94_10878(void*);
Vec3* fn_94_94E0(Vec3*,float,float,float);
Vec2* fn_94_F174(Vec2*,float,float);
void fn_94_10940(Energy*,Vec2*);
}
static inline Vec2* temp(const Vec2& v){return const_cast<Vec2*>(&v);}
static inline void apply(Accesser* a,Work* work){
if(work->isFlag(0x1200003e)){
int situation=a->modules->situation->getKind();
float* params=*reinterpret_cast<float**>(reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)3))+0x88);
short mask=1;
Vec2 speed;
__memcpy(&speed,&a->modules->kinetic->getSum(&mask),8);
int c=soValueAccesser::getConstantInt(reinterpret_cast<soModuleAccesser*>(a),0x5a04,0);
int flag=soValueAccesser::getVariableInt(reinterpret_cast<soModuleAccesser*>(a),0x520b,0)<c;
Work* w=a->modules->work;
w->clearAll(2);
speed.x/=params[1];
if(flag) w->onFlag(0x22000011);
w->onFlag(0x22000012);
w->offFlag(0x22000010);
fn_94_10878(a);
if(situation!=2){
Energy* e=static_cast<Energy*>(__dynamic_cast(a->modules->kinetic->getEnergy(3),0,lbl_94_data_9804,lbl_94_data_4570,1));
Vec3 v;
e->reset(0,temp(Vec2(speed.x,lbl_94_rodata_40)),fn_94_94E0(&v,lbl_94_rodata_40,lbl_94_rodata_40,lbl_94_rodata_40),a);
reinterpret_cast<unsigned char*>(e)[5]|=0x80;
}else{
Energy* e=static_cast<Energy*>(__dynamic_cast(a->modules->kinetic->getEnergy(3),0,lbl_94_data_9804,lbl_94_data_4570,1));
Vec3 v;
e->reset(9,temp(Vec2(speed.x,lbl_94_rodata_40)),fn_94_94E0(&v,lbl_94_rodata_40,lbl_94_rodata_40,lbl_94_rodata_40),a);
fn_94_10940(e,fn_94_F174(temp(Vec2()),params[2],*reinterpret_cast<float*>(reinterpret_cast<char*>(e)+0x24)));
reinterpret_cast<unsigned char*>(e)[5]|=0x80;
Energy* g=static_cast<Energy*>(__dynamic_cast(a->modules->kinetic->getEnergy(1),0,lbl_94_data_98E4,lbl_94_data_4570,1));
Vec3 v2;
g->reset(0,temp(Vec2(lbl_94_rodata_40,speed.y)),fn_94_94E0(&v2,lbl_94_rodata_40,lbl_94_rodata_40,lbl_94_rodata_40),a);
reinterpret_cast<unsigned char*>(g)[5]|=0x80;
}
work->offFlag(0x1200003e);
}
}
extern "C" void fn_94_10954(void*,Accesser* a){
int status=a->modules->status->getStatusKind();
Work* work=a->modules->work;
apply(a,work);
switch(status){
case 0x122: case 0x124:{
short m=1; Vec2 speed2;
__memcpy(&speed2,&a->modules->kinetic->getSum(&m),8);
fn_94_10878(a);
Energy* e=static_cast<Energy*>(__dynamic_cast(a->modules->kinetic->getEnergy(3),0,lbl_94_data_9804,lbl_94_data_4570,1));
Vec3 v;
e->reset(0,temp(Vec2(speed2.x,lbl_94_rodata_40)),fn_94_94E0(&v,lbl_94_rodata_40,lbl_94_rodata_40,lbl_94_rodata_40),a);
reinterpret_cast<unsigned char*>(e)[5]|=0x80;
break;}
case 0x123: case 0x125:{
short m=1; Vec2 speed2;
__memcpy(&speed2,&a->modules->kinetic->getSum(&m),8);
float* params2=*reinterpret_cast<float**>(reinterpret_cast<char*>(g_ftCommonDataAccesser.getData((ftKind)3))+0x88);
fn_94_10878(a);
Energy* e=static_cast<Energy*>(__dynamic_cast(a->modules->kinetic->getEnergy(3),0,lbl_94_data_9804,lbl_94_data_4570,1));
Vec3 v;
e->reset(9,temp(Vec2(speed2.x,lbl_94_rodata_40)),fn_94_94E0(&v,lbl_94_rodata_40,lbl_94_rodata_40,lbl_94_rodata_40),a);
fn_94_10940(e,fn_94_F174(temp(Vec2()),params2[2],*reinterpret_cast<float*>(reinterpret_cast<char*>(e)+0x24)));
reinterpret_cast<unsigned char*>(e)[5]|=0x80;
Energy* g=static_cast<Energy*>(__dynamic_cast(a->modules->kinetic->getEnergy(1),0,lbl_94_data_98E4,lbl_94_data_4570,1));
Vec3 v2;
g->reset(0,temp(Vec2(lbl_94_rodata_40,speed2.y)),fn_94_94E0(&v2,lbl_94_rodata_40,lbl_94_rodata_40,lbl_94_rodata_40),a);
reinterpret_cast<unsigned char*>(g)[5]|=0x80;
break;}
}
}
