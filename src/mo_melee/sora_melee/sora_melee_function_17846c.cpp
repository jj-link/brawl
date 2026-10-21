#pragma force_active on

typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern "C" void fn_27_174C08(s32 a, void* b, void* c);
extern const f32 lbl_27_rodata_2328;

class Sub5C {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual f32 vf16(void* a);
    virtual void vf17();
    virtual f32 vf18();
};

class Mid {
public:
    u8 m_pad[0x5c];
    Sub5C* m_sub;
};

class Obj {
public:
    u8 m_pad[0xd8];
    Mid* m_mid;
};

struct Vec3 {
    f32 x, y, z;
};

struct Words {
    s32 x, y, z;
};

struct Params {
    s32 a, b;
    Vec3 v;
    f32 f, g;
};

extern "C" void fn_27_17846C(s32 arg0, void* arg1) {
    Vec3 t;
    Params p;

    t.x = lbl_27_rodata_2328;
    t.y = lbl_27_rodata_2328;
    t.z = lbl_27_rodata_2328;
    p.a = 0x1d;
    p.b = 0;
    *(Words*)&p.v = *(Words*)&t;
    p.f = ((Obj*)arg1)->m_mid->m_sub->vf16(arg1);
    p.g = ((Obj*)arg1)->m_mid->m_sub->vf18();
    fn_27_174C08(arg0, &p, arg1);
}
