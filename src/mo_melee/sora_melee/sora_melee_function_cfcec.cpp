#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    s32 unk8;
};

extern "C" {
s32 fn_27_CFCEC(Obj* p) {
    s32 x = p->unk8;
    return (s32)(((u32)x << 7) & 0xFF000000) >> 25;
}
}
