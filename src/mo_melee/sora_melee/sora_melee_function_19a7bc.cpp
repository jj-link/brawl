#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_19A7BC_arg {
    u32 pad[2];
    u32 field;
};

extern "C" s32 fn_27_19A7BC(fn_27_19A7BC_arg* p)
{
    return ((s32)((p->field << 6) & 0xF0000000)) >> 29;
}
