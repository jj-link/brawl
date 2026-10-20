#pragma force_active on
extern "C" void* fn_27_FC8F4(char* p, int idx)
{
    int i = (*(int*)(p + 0x18) >> 29) + idx;
    if (i >= 3) {
        i -= 3;
    }
    return p + i * 12 + 0x1c;
}
