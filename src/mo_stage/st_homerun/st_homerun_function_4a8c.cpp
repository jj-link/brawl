#pragma force_active on

extern "C" void fn_801341D8(void*, void*);
extern "C" void fn_801342C8(void*, void*);
extern "C" const float lbl_88_rodata_E8[];
extern "C" const float lbl_88_rodata_F4;

typedef unsigned int u32;

struct Vec2f { float x, y; };
struct Vec3f {
    float x, y, z;
    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }
};
struct Matrix { float m[12]; };

struct Obj {
    virtual void f0();
    virtual int f1();
};

struct Arg0 {
    unsigned char pad[0x170];
    u32 *field_170;
    unsigned char pad_174[8];
    unsigned char *field_17c;
};

struct Arg1 {
    unsigned char pad[0x10];
    u32 field_10;
    unsigned char pad_14[0x4c];
    Obj *field_60;
};

extern "C" void fn_88_4A8C(Arg0 *arg0, Arg1 *arg1) {
    if (arg0->field_17c != 0 && *arg0->field_170 == arg1->field_10) {
        Matrix a;
        Vec2f b;
        Vec3f out;
        if (arg1->field_60->f1() == 2) {
            fn_801341D8(arg1, &a);
            out.set(a.m[2], a.m[3], lbl_88_rodata_E8[0]);
        } else {
            fn_801342C8(arg1, &b);
            out.set(b.x, b.y, lbl_88_rodata_E8[0]);
        }
        if (out.y < lbl_88_rodata_F4) {
            *arg0->field_17c = 1;
        }
    }
}