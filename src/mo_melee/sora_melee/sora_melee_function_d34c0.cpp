#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_D34C0(Obj* p) {
    u32 w = p->unk8;
    return (s32)((w << 3) & 0xF0000000) >> 29;
}
