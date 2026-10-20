#pragma force_active on
typedef int s32;

extern "C" {
void *fn_27_1C716C(void *p, s32 idx)
{
    s32 v = *(s32 *)((char *)p + 0x18);
    s32 i = (v >> 28) + idx;
    if (i >= 5) {
        i -= 5;
    }
    return (char *)p + i * 12 + 0x1c;
}
}
