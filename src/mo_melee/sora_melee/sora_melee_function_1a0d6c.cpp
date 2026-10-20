#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
s32 fn_27_1A0D6C(Obj *p) {
    u32 x = p->flags;
    return ((s32)((x << 6) & 0xF0000000)) >> 29;
}
}
