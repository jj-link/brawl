#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_41A0C(FnObj* p) {
    u32 f = (p->unk8 >> 23) & 0x1F;
    return ((s32)(f << 27)) >> 28;
}
}
