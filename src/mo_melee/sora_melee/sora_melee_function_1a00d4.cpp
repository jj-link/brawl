#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1A00D4_obj {
    char pad[8];
    u32 field;
};

extern "C" s32 fn_27_1A00D4(fn_27_1A00D4_obj *p)
{
    u32 v = p->field;
    return (s32)((v << 4) & 0xE0000000) >> 30;
}
