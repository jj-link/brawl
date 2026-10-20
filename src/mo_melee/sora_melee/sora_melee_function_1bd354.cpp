#pragma force_active on
typedef unsigned char u8;

extern "C" u8* fn_27_1BD354(u8* p, int idx)
{
    int v = *(int*)(p + 0x18);
    int i = (v >> 26) + idx;
    if (i >= 0x18) {
        i -= 0x18;
    }
    return p + i * 12 + 0x1c;
}
