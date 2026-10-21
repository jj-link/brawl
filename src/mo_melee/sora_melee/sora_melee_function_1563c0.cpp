#include <types.h>
#pragma force_active on

#define VF(n) virtual s32 f##n();

struct Eff {
    VF(0) VF(1) VF(2) VF(3) VF(4) VF(5) VF(6) VF(7) VF(8)
    VF(9) VF(10) VF(11) VF(12) VF(13) VF(14) VF(15)
    virtual s32 f16();
};

struct Act1 {
    VF(0) VF(1) VF(2) VF(3)
    virtual s32 f4(u32 x);
};

struct Act2 {
    VF(0) VF(1) VF(2) VF(3)
    virtual s32 f4(u32 x, void* p);
};

extern "C" s32 fn_27_1563C0(void* unused, u8* obj) {
    u8* p = *(u8**)(obj + 0xd8);
    Eff* e = *(Eff**)(p + 0x70);
    if (e->f16() == 0xC0) {
        goto c0;
    }
    {
        Act2* c = *(Act2**)(*(u8**)(obj + 0xd8) + 0x64);
        if (c->f4(0x1000000E, *(u8**)(obj + 0xd8)) > 0) {
            goto zero;
        }
    }
    return 1;
c0:
    {
        Act1* a = *(Act1**)(*(u8**)(obj + 0xd8) + 0x64);
        if (a->f4(0x20000000) != 2) {
            goto zero;
        }
        Act2* b = *(Act2**)(*(u8**)(obj + 0xd8) + 0x64);
        if (b->f4(0x1000000E, *(u8**)(obj + 0xd8)) > 0) {
            goto zero;
        }
    }
    return 1;
zero:
    return 0;
}
