#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_1E7DC4(Obj* p) {
    u32 x = p->unk8;
    u32 v = ((x << 4) | (x >> 28)) & 0xE0000000;
    return (s32)v >> 30;
}
}
