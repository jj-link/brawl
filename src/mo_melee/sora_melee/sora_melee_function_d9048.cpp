#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct Fn27Obj {
    u8 pad0[8];
    s32 unk8;
};

extern "C" {
void* fn_27_D9048(Fn27Obj* p, s32 idx) {
    s32 t = p->unk8 >> 29;
    s32 n = t + idx;
    if (n >= 3) {
        n -= 3;
    }
    return (u8*)p + n * 16 + 12;
}
}
