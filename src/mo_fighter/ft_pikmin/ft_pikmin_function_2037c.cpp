#include <so/so_value_accesser.h>
#pragma force_active on
#pragma opt_propagation off
struct Vec2 { float x,y; };
struct Status {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void reset();
};
struct Posture {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual float lr();
};
struct Modules {
 char pad0[0xc]; Posture* posture; char pad1[0x6c]; Status* status;
};
struct Access { char pad[0xd8]; Modules* mods; };
struct Flag { unsigned char value; };
struct Temp { char data[0x34]; };
extern "C" {
extern const float lbl_113_rodata_90;
extern const float lbl_113_rodata_94;
Temp* fn_113_1E0A0(Temp*, const Vec2*, const Vec2*, const Vec2*, const Vec2*, const Vec2*, unsigned char, unsigned char);
void* fn_113_1E164(void*, Temp*);
void fn_113_4730(Temp*, short);
void fn_113_BC00(Vec2*, const Vec2*);
}
extern "C" void fn_113_2037C(void*, char* owner, Access* access) {
 access->mods->status->reset();
 Flag flag = {0};
 char* obj = owner + 0x10;
 Vec2 e,d,v,b,a;
 a.x=lbl_113_rodata_94; a.y=lbl_113_rodata_94;
 b.x=lbl_113_rodata_90; b.y=lbl_113_rodata_90;
 v.x=lbl_113_rodata_94; v.y=lbl_113_rodata_94;
 d.x=lbl_113_rodata_90; d.y=lbl_113_rodata_90;
 e.x=lbl_113_rodata_90; e.y=lbl_113_rodata_90;
 Temp temp;
 fn_113_1E0A0(&temp,&e,&d,&v,&b,&a,0,0);
 fn_113_1E164(obj,&temp);
 fn_113_4730(&temp,0);
 float speed=soValueAccesser::getConstantFloat((soModuleAccesser*)access,0xfb9,0);
 if(access->mods->posture->lr()<lbl_113_rodata_90) speed=-speed;
 Vec2 velocity; velocity.x=speed; velocity.y=lbl_113_rodata_90;
 fn_113_BC00((Vec2*)(obj+8),&velocity);
 obj[5]|=0x80;
 Flag flag2 = {0};
 *(float*)(owner+0x58)=soValueAccesser::getConstantFloat((soModuleAccesser*)access,0xfba,0);
 *(float*)(owner+0x5c)=-soValueAccesser::getConstantFloat((soModuleAccesser*)access,0xfd4,0);
 *(float*)(owner+0x60)=soValueAccesser::getConstantFloat((soModuleAccesser*)access,0xfd5,0);
 owner[0x55]|=0x80;
}