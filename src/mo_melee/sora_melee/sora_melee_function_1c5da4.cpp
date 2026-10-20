#pragma force_active on
typedef unsigned char u8;

extern "C" {
void *fn_27_1C5DA4(u8 *p, int idx)
{
    int v = *(int *)(p + 0x18);
    int i = (v >> 25) + idx;
    if (i >= 0x28) {
        i -= 0x28;
    }
    return p + i * 12 + 0x1c;
}
}
