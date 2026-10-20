#pragma force_active on
extern "C" char* fn_27_1D0378(char* p, int idx)
{
    int i = (*(int*)(p + 8) >> 25) + idx;
    if (i >= 0x20) {
        i -= 0x20;
    }
    return p + i * 0xC + 0xC;
}
