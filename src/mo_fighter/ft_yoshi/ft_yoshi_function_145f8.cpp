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

struct Kinetic {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
};

struct Modules {
    char pad0[0xc];
    Obj0c* obj0c;
    char pad1[0x6c];
    Kinetic* kinetic;
};

struct Accesser {
    char pad0[0xd8];
    Modules* modules;
};

struct Params {
    char pad0[0x2c];
    float f2c;
    float f30;
    float f34;
    float f38;
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
extern const unsigned char lbl_95_data_7A88[], lbl_95_data_2C38[];
extern const float lbl_95_rodata_120;
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec3* fn_95_ABB4(Vec3*, float, float, float);
void fn_27_89D08(int, void*, int, Vec2*, Vec3*);
void fn_95_DF08(Vec2*, const Vec2*);
}

extern "C" void fn_95_145F8(void* self, int arg, Vec2* speed, Accesser* accesser) {
    Vec3 rot;
    fn_27_89D08(3, accesser, 0, speed, fn_95_ABB4(&rot, lbl_95_rodata_120, lbl_95_rodata_120, lbl_95_rodata_120));
    Params* params = *(Params**)((char*)getData__20ftCommonDataAccesserCF6ftKind(g_ftCommonDataAccesser, 4) + 0x7c);
    Kinetic* kinetic = accesser->modules->kinetic;
    char* energy = (char*)__dynamic_cast(kinetic->getEnergy(3), 0, lbl_95_data_7A88, lbl_95_data_2C38, 1);
    float scale = accesser->modules->obj0c->getScale();

    Vec2 a = {params->f2c * scale, lbl_95_rodata_120};
    fn_95_DF08((Vec2*)(energy + 0x10), &a);
    Vec2 b = {params->f30, lbl_95_rodata_120};
    fn_95_DF08((Vec2*)(energy + 0x20), &b);
    Vec2 c = {params->f38, lbl_95_rodata_120};
    fn_95_DF08((Vec2*)(energy + 0x28), &c);
    Vec2 d = {params->f34, lbl_95_rodata_120};
    fn_95_DF08((Vec2*)(energy + 0x18), &d);
}
