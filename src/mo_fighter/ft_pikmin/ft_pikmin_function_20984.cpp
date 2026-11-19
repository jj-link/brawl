#pragma force_active on
#pragma opt_propagation off

struct V2 {
    float x, y;
};

struct W {
    unsigned int a, b;
};

struct Attr {
    short v;
};

struct Temp {
    char data[0x34];
};

struct Small {
    char data[0x14];
};

struct Flag {
    unsigned char value;
};

struct Status {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12();
    virtual W v13(Attr* p);
};

struct Modules {
    char p0[0x7c];
    Status* status;
};

struct Access {
    char pad[0xd8];
    Modules* mods;
};

struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual void update();
};

extern "C" {
extern const float lbl_113_rodata_90;
extern const float lbl_113_rodata_94;
Temp* fn_113_1E0A0(Temp*, const V2*, const V2*, const V2*, const V2*, const V2*, unsigned char, unsigned char);
void* fn_113_1E164(void*, Temp*);
void fn_113_4730(Temp*, short);
void fn_113_BC00(V2*, const V2*);
void* fn_113_205EC(Small*, float, float, float);
void* fn_113_20654(void*, Small*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
}

extern "C" void fn_113_20984(void*, char* owner, Access* access) {
    access->mods->status->v12();
    Attr attr;
    attr.v = 1;
    W s;
    W r = access->mods->status->v13(&attr);
    s.a = r.a;
    s.b = r.b;
    Flag flag = {0};
    char* obj = owner + 0x10;
    V2 e, d, c, b, a;
    a.x = lbl_113_rodata_94; a.y = lbl_113_rodata_94;
    b.x = lbl_113_rodata_90; b.y = lbl_113_rodata_90;
    c.x = lbl_113_rodata_94; c.y = lbl_113_rodata_94;
    d.x = lbl_113_rodata_90; d.y = lbl_113_rodata_90;
    e.x = lbl_113_rodata_90; e.y = lbl_113_rodata_90;
    Temp temp;
    fn_113_1E0A0(&temp, &e, &d, &c, &b, &a, 0, 0);
    fn_113_1E164(obj, &temp);
    fn_113_4730(&temp, 0);
    obj[0x30] = 0;
    ((Obj*)obj)->update();
    V2 vel;
    vel.x = *(float*)&s.a;
    vel.y = lbl_113_rodata_90;
    fn_113_BC00((V2*)(obj + 8), &vel);
    obj[5] |= 0x80;
    Flag flag2 = {0};
    char* o2 = owner + 0x50;
    Small t2;
    fn_113_205EC(&t2, lbl_113_rodata_90, lbl_113_rodata_90, lbl_113_rodata_94);
    fn_113_20654(o2, &t2);
    fn_113_4730((Temp*)&t2, 0);
    float f0 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access, 0xfd4, 0);
    *(float*)(o2 + 0xc) = -f0;
    float f1 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(access, 0xfd5, 0);
    *(float*)(o2 + 0x10) = f1;
    *(float*)(o2 + 0x8) = *(float*)&s.b;
    o2[5] |= 0x80;
}
