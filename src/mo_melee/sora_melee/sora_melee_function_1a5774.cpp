#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_1A5774(Obj* p) {
    u32 x = p->unk8;
    return (s32)((x << 8) & 0xF8000000u) >> 28;
}
}
