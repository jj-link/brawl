#pragma force_active on
extern "C" char* fn_27_1B05D4(char* p, int idx)
{
    int t = ((int*)p)[2] >> 29;
    int i = t + idx;
    if (i >= 2) {
        i -= 2;
    }
    return p + i * 0x34 + 0xc;
}
