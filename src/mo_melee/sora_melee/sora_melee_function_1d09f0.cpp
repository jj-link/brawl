#pragma force_active on
extern "C" void* fn_27_1D09F0(char* p, int idx)
{
    int v = *(int*)(p + 8) >> 28;
    int i = v + idx;
    if (i >= 4) {
        i -= 4;
    }
    return p + i * 12 + 12;
}
