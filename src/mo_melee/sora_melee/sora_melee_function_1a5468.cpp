#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
s32 fn_27_1A5468(Obj* p) {
    return (s32)((p->flags << 6) & 0xF0000000) >> 29;
}
}
