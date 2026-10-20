#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_Obj {
    char pad[8];
    u32 field8;
};

extern "C" s32 fn_27_19A53C(fn_27_Obj* p)
{
    return (s32)((p->field8 << 10) & 0xFC000000) >> 27;
}
