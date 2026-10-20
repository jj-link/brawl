#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct FnObj {
    u8 pad00[0x20];
    s32 m20;
    s32 m24;
    s32 m28;
    u8 m2C[5];
    u8 m31;
    u8 m32;
};

extern "C" void fn_27_4256C(FnObj* p) {
    if (p->m31 == 1 || p->m24 != 0) {
        p->m20 = 2;
        return;
    }
    if (p->m32 == 1 || p->m28 != 0) {
        p->m20 = 1;
        return;
    }
    p->m20 = 0;
}
