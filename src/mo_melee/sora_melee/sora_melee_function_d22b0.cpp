#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    char pad[8];
    u32 unk8;
};

extern "C" {
s32 fn_27_D22B0(Obj* p) {
    u32 x = p->unk8;
    return (s32)((x << 8) & 0xF8000000) >> 28;
}
}
