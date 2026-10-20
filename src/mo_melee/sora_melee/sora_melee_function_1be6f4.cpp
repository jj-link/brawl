#pragma force_active on
typedef int s32;

extern "C" void *fn_27_1BE6F4(void *self, s32 idx)
{
    s32 v = *(s32 *)((char *)self + 0x18);
    s32 n = (v >> 26) + idx;
    if (n >= 0x12) {
        n -= 0x12;
    }
    return (char *)self + n * 12 + 0x1c;
}
