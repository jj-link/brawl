#pragma force_active on
extern "C" void* fn_62_A4D4(char* base, int index)
{
    int n = (*(int*)(base + 8) >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return base + n * 0xa0 + 0xc;
}
