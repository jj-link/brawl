#pragma force_active on
typedef int s32;

extern "C" void *fn_27_389E24(char *p, s32 idx)
{
    s32 n = *(s32 *)(p + 8) >> 28;
    s32 i = n + idx;
    if (i >= 4) {
        i -= 4;
    }
    return p + i * 4 + 0xc;
}
