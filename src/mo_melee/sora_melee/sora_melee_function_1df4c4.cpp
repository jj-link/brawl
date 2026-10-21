#include <types.h>
#pragma force_active on

#define VF(n) virtual void f##n();

struct Prefix {
    s32 a;
    s32 b;
};

struct X : Prefix {
    VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8) VF(9)
    VF(10) VF(11) VF(12) VF(13) VF(14) VF(15) VF(16) VF(17) VF(18) VF(19)
    VF(20) VF(21) VF(22) VF(23) VF(24) VF(25) VF(26) VF(27) VF(28) VF(29)
    VF(30) VF(31)
    virtual s32 f32();
    VF(33) VF(34) VF(35) VF(36) VF(37) VF(38) VF(39) VF(40) VF(41) VF(42)
    virtual void f43(s32 x);
};

struct Holder {
    VF(0) VF(1) VF(2) VF(3)
    virtual s32 f4(u32 x);
    VF(5) VF(6) VF(7) VF(8) VF(9) VF(10) VF(11) VF(12) VF(13) VF(14)
    VF(15) VF(16) VF(17)
    virtual void f18(u32 x);
};

struct Mid {
    char pad0[0x64];
    Holder* holder;
    char pad1[0x9c - 0x68];
    X* x;
};

struct Owner {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_1DF4C4(void* unused, Owner* obj) {
    s32 n = obj->mid->x->f32();
    if (n > 0) {
        s32 v = obj->mid->holder->f4(0x20000001);
        if (v <= 0) {
            v = 1;
        } else if (v > n) {
            v = n;
        }
        obj->mid->x->f43(v);
    } else {
        obj->mid->holder->f18(0x22000000);
    }
}
