#pragma force_active on

struct Vec2 { float x, y; };
struct Vec3 { float x, y, z; };

struct Accesser;

struct Obj0c {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float getScale();
};

struct Energy {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void resetEnergy(int, Vec2*, Vec3*, Accesser*);
};

struct Kinetic {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
};

struct Modules {
    char pad0[0xc];
    Obj0c* obj0c;
    char pad1[0x6c];
    Kinetic* kinetic;
};

struct Accesser {
    char pad0[8];
    void* owner;
    char pad1[0xcc];
    Modules* modules;
};

struct Params {
    float f0, f4, f8, fC, f10, f14, f18, f1c, f20;
};

extern "C" {
extern const unsigned char lbl_95_data_7A88[], lbl_95_data_2C38[], lbl_95_data_810C[];
extern const char lbl_95_data_5F8[], lbl_95_data_36D8[];
extern const float lbl_95_rodata_120;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_95_A108(void*);
Vec3* fn_95_ABB4(Vec3*, float, float, float);
void fn_95_DF08(Vec2*, const Vec2*);
}

extern "C" void fn_95_14F2C(void*, void*, Vec2* speed, Accesser* accesser) {
    Modules* modules = accesser->modules;
    Kinetic* kinetic = modules->kinetic;
    float scale = modules->obj0c->getScale();
    Energy* stop = static_cast<Energy*>(__dynamic_cast(
        kinetic->getEnergy(3), 0, lbl_95_data_7A88, lbl_95_data_2C38, 1));
    Energy* gravity = static_cast<Energy*>(__dynamic_cast(
        kinetic->getEnergy(1), 0, lbl_95_data_810C, lbl_95_data_2C38, 1));
    Params* params = *(Params**)((char*)fn_95_A108(__dynamic_cast(
        accesser->owner, 0x3c, lbl_95_data_5F8, lbl_95_data_36D8, 1)) + 0xc);
    kinetic->v12();

    Vec3 zero3;
    Vec2 zero2 = {lbl_95_rodata_120, lbl_95_rodata_120};
    fn_95_ABB4(&zero3, lbl_95_rodata_120, lbl_95_rodata_120, lbl_95_rodata_120);

    Vec2 a = {speed->x, lbl_95_rodata_120};
    stop->resetEnergy(0x16, &a, &zero3, accesser);

    Vec2 h = {params->f4 * scale, lbl_95_rodata_120};
    fn_95_DF08((Vec2*)((char*)stop + 0x10), &h);
    Vec2 i = {params->f0, lbl_95_rodata_120};
    fn_95_DF08((Vec2*)((char*)stop + 0x18), &i);
    Vec2 j = {params->f8, lbl_95_rodata_120};
    fn_95_DF08((Vec2*)((char*)stop + 0x28), &j);
    Vec2 k = {params->fC, lbl_95_rodata_120};
    fn_95_DF08((Vec2*)((char*)stop + 0x20), &k);
    ((unsigned char*)stop)[5] |= 0x80;

    float gy = speed->y;
    Vec2 g = {lbl_95_rodata_120, gy};
    gravity->resetEnergy(0, &g, &zero3, accesser);
    *(float*)((char*)gravity + 0x10) = -params->f18;
    *(float*)((char*)gravity + 0x14) = params->f20;
    *(float*)((char*)gravity + 0x1c) = params->f14;
    *(float*)((char*)gravity + 0x18) = params->f18;
    ((unsigned char*)gravity)[5] |= 0x80;
}
