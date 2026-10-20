#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct fn27Obj {
    u8 pad[8];
    s32 field8;
};

extern "C" {
void* fn_27_1B05AC(fn27Obj* p, s32 idx) {
    s32 i = (p->field8 >> 29) + idx;
    if (i >= 3) {
        i -= 3;
    }
    return (u8*)p + i * 0x34 + 0xc;
}
}
