#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_FE800_Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
s32 fn_27_FE800(fn_27_FE800_Obj* obj) {
    u32 x = obj->flags;
    u32 field = (x >> 27) & 7;
    return (s32)(field << 29) >> 30;
}
}
