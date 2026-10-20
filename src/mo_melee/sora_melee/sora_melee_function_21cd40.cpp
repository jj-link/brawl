#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u32 unk0;
    u32 unk4;
};

extern "C" s32 fn_27_21CD40(Obj* p) {
    return (s32)((p->unk4 << 21) & 0xFF000000) >> 25;
}
