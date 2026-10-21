#pragma force_active on

typedef unsigned char u8;
typedef int s32;

extern "C" bool fn_41_1AE7C(void* p);

struct FnObj {
    u8 pad0[0x24];
    float f24;
    u8 pad1[0x24];
    float f4c;
};

extern "C" bool fn_41_1CA50(FnObj* p) {
    if (fn_41_1AE7C(p) == 1) {
        return false;
    }
    if ((s32)p->f24 == 0x8bcf) {
        return false;
    }
    if ((s32)p->f24 == 0x8bd3) {
        return false;
    }
    return !(p->f4c < p->f24);
}
