#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1B2018_obj {
    char pad[8];
    u32 field8;
};

extern "C" {
s32 fn_27_1B2018(fn_27_1B2018_obj* p)
{
    return (s32)(((p->field8 >> 16) & 0x3F) << 26) >> 27;
}
}
