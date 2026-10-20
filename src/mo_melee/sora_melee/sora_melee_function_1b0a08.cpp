#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Obj {
    u8 pad0[8];
    s32 unk8;
};

extern "C" void* fn_27_1B0A08(Obj* p, s32 idx) {
    s32 t = p->unk8 >> 22;
    s32 s = t + idx;
    if (s >= 0x120) {
        s -= 0x120;
    }
    return (u8*)p + s * 4 + 0xc;
}
