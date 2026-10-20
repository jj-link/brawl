#pragma force_active on
typedef unsigned char u8;

extern "C" u8* fn_27_1B0C38(u8* base, int idx)
{
    int s = *(int*)(base + 8) >> 26;
    int t = s + idx;
    if (t >= 20) {
        t -= 20;
    }
    return base + t * 20 + 12;
}
