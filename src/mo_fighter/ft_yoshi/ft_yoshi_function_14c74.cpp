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
extern const unsigned char lbl_95_data_7A88[], lbl_95_data_2C38[], lbl_95_data_810C[], lbl_95_data_81D8[];
extern const char lbl_95_data_5F8[], lbl_95_data_36D8[];
extern const float lbl_95_rodata_120;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_95_A108(void*);
Vec3* fn_95_ABB4(Vec3*, float, float, float);
void fn_95_DF08(Vec2*, const Vec2*);
void fn_95_1473C(Vec2*, float, float);
}

extern "C" void fn_95_14C74(void*, void*, Vec2* pos, Accesser* accesser) {
    Modules* modules = accesser->modules;
    Kinetic* kinetic = modules->kinetic;
    modules->obj0c->getScale();
    Params* params = *(Params**)((char*)fn_95_A108(__dynamic_cast(
        accesser->owner, 0x3c, lbl_95_data_5F8, lbl_95_data_36D8, 1)) + 0xc);
    __dynamic_cast(kinetic->getEnergy(3), 0, lbl_95_data_7A88, lbl_95_data_2C38, 1);
    Energy* gravity = static_cast<Energy*>(__dynamic_cast(
        kinetic->getEnergy(1), 0, lbl_95_data_810C, lbl_95_data_2C38, 1));
    Energy* r30 = static_cast<Energy*>(__dynamic_cast(
        kinetic->getEnergy(2), 0, lbl_95_data_81D8, lbl_95_data_2C38, 1));

    Vec2 p = *pos;
    Vec2 b = {lbl_95_rodata_120, lbl_95_rodata_120};
    Vec2 a;
    a.y = lbl_95_rodata_120;
    a.x = p.x;
    kinetic->v12();
    if (p.y < -params->f20 || p.y > lbl_95_rodata_120) {
        b.y = lbl_95_rodata_120;
        a.y = p.y;
    } else {
        b.y = p.y;
        a.y = lbl_95_rodata_120;
        ((unsigned char*)gravity)[5] |= 0x80;
    }

    Vec2 c = {lbl_95_rodata_120, lbl_95_rodata_120};
    Vec3 z;
    fn_95_ABB4(&z, lbl_95_rodata_120, lbl_95_rodata_120, lbl_95_rodata_120);
    gravity->resetEnergy(0, &b, &z, accesser);
    *(float*)((char*)gravity + 0x10) = -params->f1c;
    *(float*)((char*)gravity + 0x14) = params->f20;
    *(float*)((char*)gravity + 0x1c) = params->f20;
    *(float*)((char*)gravity + 0x18) = lbl_95_rodata_120;

    r30->resetEnergy(0xb, &c, &z, accesser);
    fn_95_DF08((Vec2*)((char*)r30 + 0x8), &a);
    *(float*)((char*)r30 + 0x3c) = params->f4;
    Vec2* q = (Vec2*)((char*)r30 + 0x40);
    q->x = lbl_95_rodata_120;
    float f10 = params->f10;
    q->y = f10;
    *(float*)((char*)r30 + 0x48) = lbl_95_rodata_120;

    Vec2 v18;
    fn_95_1473C(&v18, params->f8, params->f14);
    fn_95_DF08((Vec2*)((char*)r30 + 0x18), &v18);
    Vec2 v10;
    fn_95_1473C(&v10, params->f8, params->f14);
    fn_95_DF08((Vec2*)((char*)r30 + 0x28), &v10);
    Vec2 v8;
    fn_95_1473C(&v8, params->fC, params->f18);
    fn_95_DF08((Vec2*)((char*)r30 + 0x20), &v8);
    ((unsigned char*)r30)[5] |= 0x80;
}
