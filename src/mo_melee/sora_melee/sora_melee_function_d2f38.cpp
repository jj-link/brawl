#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    s32 field8;
};

extern "C" s32 fn_27_D2F38(FnObj* p) {
    s32 t = p->field8;
    t = (t << 3) & 0xF0000000;
    return t >> 29;
}
