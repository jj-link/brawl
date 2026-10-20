#pragma force_active on
typedef unsigned int u32;

extern "C" char* fn_27_1E5134(char* p, int idx)
{
    int n = (*(int*)(p + 0x18) >> 30) + idx;
    if (n >= 1) {
        n -= 1;
    }
    return p + 0x1c + n * 12;
}
