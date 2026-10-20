#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_1B1A64_Arg {
    u32 unk0;
    u32 unk4;
    char *base;
    s32 count;
};

extern "C" void *fn_27_1B1A64(fn_27_1B1A64_Arg *p)
{
    return p->base + p->count * 12 + 4;
}
