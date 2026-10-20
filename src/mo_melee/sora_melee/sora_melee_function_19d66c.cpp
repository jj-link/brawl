#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct ftBits {
    u32 pad0;
    u32 pad1;
    u32 bits;
};

extern "C" s32 fn_27_19D66C(ftBits *p)
{
    return (s32)(p->bits << 3 & 0xF0000000) >> 29;
}
