#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_27_21FB34(void **self, u32 bit)
{
    u32 v = *(u32 *)((char *)*self + 0x160) & (1u << bit);
    return v != 0;
}
