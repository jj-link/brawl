#include <types.h>
#pragma force_active on

struct Vec {
    f32 x, y, z;

    Vec(f32 a, f32 b, f32 c) : x(a), y(b), z(c) {}
};

class Obj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual Vec s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15(void*, u32);
};

class Obj2 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6(u32, const Vec&, const Vec&, u32, s32, f32);
};

struct Mid {
    u8 pad0[0xC];
    Obj* a;
    u8 pad1[0x78];
    Obj2* b;
};

struct Outer {
    u8 pad[0xD8];
    Mid* m;
};

extern const f32 lbl_27_rodata_77E8;
extern const f32 lbl_27_rodata_77EC;

extern "C" void fn_27_341C20(void*, Outer* self) {
    Mid* mid = self->m;
    Obj* obj = mid->a;
    Obj2* obj2 = mid->b;
    Vec sp20(lbl_27_rodata_77E8, lbl_27_rodata_77E8, lbl_27_rodata_77E8);

    obj->s15(&sp20, 0);
    obj2->s6(
        0x22,
        obj->s4(),
        Vec(lbl_27_rodata_77E8, lbl_27_rodata_77E8, lbl_27_rodata_77E8),
        0,
        -1,
        lbl_27_rodata_77EC
    );
}
