#pragma force_active on
struct Vec2 {
    float x, y;
};

struct Vec2c {
    float x, y;
    Vec2c(float a, float b) : x(a), y(b) {}
};

struct Vec3 {
    float x, y, z;
};

class EnergyModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
};

class KineticEnergy {
public:
    virtual void s0();
    virtual void s1();
    virtual Vec2 s2();
};

struct Modules {
    char pad[0x7c];
    EnergyModule* kinetic;
};

struct Accesser {
    char pad0[8];
    void* owner;
    char pad1[0xcc];
    Modules* modules;
};

struct Params {
    char pad[4];
    float* values;
};

extern "C" {
extern const char lbl_107_data_5E0[];
extern const char lbl_107_data_45B8[];
extern const char lbl_107_data_3B18[];
extern const char lbl_107_data_8CA4[];
extern const float lbl_107_rodata_38;

void* __dynamic_cast(void*, long, const void*, const void*, short);
Params* fn_107_A8C4(void*);
Vec3* fn_107_B444(Vec3*, float, float, float);
void fn_27_89D08(int, Accesser*, int, Vec2*, Vec3*);
void fn_107_EF04(Vec2*, const Vec2*);

void fn_107_10374(void* arg1, int arg2, const Vec2* input, Accesser* a) {
    Vec2 speed = *input;
    short flag = 1;
    float* p = fn_107_A8C4(__dynamic_cast(
        a->owner, 0x3c, lbl_107_data_5E0, lbl_107_data_45B8, flag))->values;
    KineticEnergy* e = (KineticEnergy*)__dynamic_cast(
        a->modules->kinetic->getEnergy(3), 0,
        lbl_107_data_8CA4, lbl_107_data_3B18, flag);

    e->s2();

    Vec2c gravity(lbl_107_rodata_38, speed.y);
    Vec3 rot1;
    fn_27_89D08(1, a, 0, (Vec2*)&gravity,
        fn_107_B444(&rot1, lbl_107_rodata_38,
                    lbl_107_rodata_38, lbl_107_rodata_38));

    Vec2 motion;
    Vec2 ret = e->s2();
    motion.x = ret.x;
    motion.y = lbl_107_rodata_38;
    Vec3 rot2;
    fn_27_89D08(3, a, 9, &motion,
        fn_107_B444(&rot2, lbl_107_rodata_38,
                    lbl_107_rodata_38, lbl_107_rodata_38));

    Vec2 limit = {p[1], lbl_107_rodata_38};
    fn_107_EF04((Vec2*)((char*)e + 0x20), &limit);
}
}
