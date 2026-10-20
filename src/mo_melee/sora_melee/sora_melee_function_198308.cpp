#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_198308_arg {
    u32 pad[2];
    u32 v;
};

extern "C" s32 fn_27_198308(fn_27_198308_arg* p)
{
    return (s32)((p->v << 4) & 0xF8000000) >> 28;
}
