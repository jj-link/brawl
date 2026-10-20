#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct fn_27_D3268_Arg {
    char pad[8];
    u32 word;
};

extern "C" {
s32 fn_27_D3268(fn_27_D3268_Arg* p)
{
    s32 v = (s32)(((p->word >> 23) & 0x1F) << 27);
    return v >> 28;
}
}
