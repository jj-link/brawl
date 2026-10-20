#pragma force_active on
typedef unsigned int u32;

struct Word8 {
    u32 pad0 : 3;
    u32 field : 3;
    u32 pad1 : 26;
};

extern "C" {
void fn_27_1980A0(void *obj, int val)
{
    Word8 *w = (Word8 *)((char *)obj + 8);
    w->field = val;
}
}
