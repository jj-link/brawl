#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_1048;

struct Vec2 {
    f32 x;
    f32 y;
};

struct IVec2 {
    s32 x;
    s32 y;
};

union FI {
    f32 f[2];
    s32 i[2];
};

struct FlagBits {
    u8 high : 7;
    u8 low : 1;
};

class Iface {
public:
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
    virtual void f23(s32 a, u32 b, Vec2* c);
    virtual void f24();
};

extern "C" void fn_27_13231C(u8* self, u32 arg1, s32 arg2) {
    if (arg1 == 1) {
        if ((self[0x138] & 1) == 0) {
            IVec2 out;
            FI src;
            src.f[0] = lbl_27_rodata_1048;
            src.f[1] = lbl_27_rodata_1048;
            out.x = src.i[0];
            out.y = src.i[1];
            Iface* c = *(Iface**)(*(u8**)(*(u8**)(self + 0x60) + 0xd8) + 0x60);
            c->f23(arg2, 0, (Vec2*)&out);
            self[0x138] = self[0x138] | 1;
        }
    } else {
        u8 flags = self[0x138];
        if ((u32)(flags & 1) == 1) {
            ((FlagBits*)(self + 0x138))->low = 0;
            Iface* c = *(Iface**)(*(u8**)(*(u8**)(self + 0x60) + 0xd8) + 0x60);
            c->f24();
        }
    }
}
