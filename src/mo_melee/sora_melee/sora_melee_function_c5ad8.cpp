#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_C5AD8_S {
    u32 w0;
    u32 w1;
    u32 pad0 : 2;
    s32 field : 2;
    u32 pad1 : 28;
};

extern "C" s32 fn_27_C5AD8(fn_27_C5AD8_S* p)
{
    return p->field;
}
