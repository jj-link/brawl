#include <math.h>
#pragma force_active on
struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };
#pragma pack(push, 4)
union Pair { unsigned long long u; Vec2 v; };
#pragma pack(pop)
struct Object {
    virtual void v0();
    virtual void v1();
    virtual unsigned long long get();
    unsigned char flags[4];
    Vec2 a,b,c,d,e;
    unsigned char f,g,h;
};
struct Status {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void reset();
};
struct Posture {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual Vec3 getPos();
};
struct Work {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void setInt(int, unsigned int);
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12();
    virtual void setFloat(float, unsigned int);
};
struct Modules {
    char p0[0xc]; Posture* posture;
    char p1[0x64-0x10]; Work* work;
    char p2[0x7c-0x68]; Status* status;
};
struct Access { char pad[0xd8]; Modules* mods; };
struct GlobalBase { char pad[0x3c]; };
struct Global : GlobalBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual float get(int);
};
struct Flag { unsigned char value; };
struct Temp { char data[0x34]; };
extern "C" {
extern const float lbl_113_rodata_180;
extern const float lbl_113_rodata_178;
extern Global* lbl_27_bss_5668;
Temp* fn_113_1E0A0(Temp*, const Vec2*, const Vec2*, const Vec2*, const Vec2*, const Vec2*, unsigned char, unsigned char);
Object* fn_113_1E164(Object*, Temp*);
void fn_113_4730(Temp*, short);
void fn_113_BC00(Vec2*, const Vec2*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(Access*, unsigned long, unsigned long);
}
extern "C" void fn_113_2A840(void*, char* owner, Access* access) {
    Status* status = access->mods->status;
    status->reset();
    Flag flag = {0};
    Object* obj = (Object*)(owner + 0x10);
    Vec2 e,d,c,b,a;
    a.x=lbl_113_rodata_180; a.y=lbl_113_rodata_180;
    b.x=lbl_113_rodata_178; b.y=lbl_113_rodata_178;
    c.x=lbl_113_rodata_180; c.y=lbl_113_rodata_180;
    d.x=lbl_113_rodata_178; d.y=lbl_113_rodata_178;
    e.x=lbl_113_rodata_178; e.y=lbl_113_rodata_178;
    Temp temp;
    fn_113_1E0A0(&temp,&e,&d,&c,&b,&a,0,0);
    fn_113_1E164(obj,&temp);
    fn_113_4730(&temp,0);
    float v = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access,0xfa4,0);
    Vec2 vel; vel.x=lbl_113_rodata_178; vel.y=v;
    fn_113_BC00(&obj->a,&vel);
    obj->flags[1] |= 0x80;
    Pair speed; speed.u=obj->get();
    double absolute = fabs(speed.v.y);
    float y = absolute;
    Posture* posture=access->mods->posture;
    float time=posture->getPos().y/y;
    Work* work=access->mods->work;
    work->setInt((int)time,0x20000000);
    Global* global=lbl_27_bss_5668;
    if(global) {
        float value=global->get(2);
        float minimum=getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access,0xfa6,0);
        if(time<minimum) time=minimum;
        float result=-(value/time);
        work=access->mods->work;
        work->setFloat(result,0x21000000);
    }
}
