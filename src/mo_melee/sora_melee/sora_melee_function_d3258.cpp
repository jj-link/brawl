#pragma force_active on
typedef unsigned int u32;

struct Word8 {
    u32 hi : 4;
    u32 rest : 28;
};

extern "C" {
void fn_27_D3258(void *p, u32 v)
{
    Word8 *w = (Word8 *)((char *)p + 8);
    w->hi = v;
}
}
