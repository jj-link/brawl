#pragma force_active on
typedef signed int s32;

extern "C" {
void* fn_27_D9430(void* p, s32 idx)
{
    s32 t = ((s32*)p)[2] >> 29;
    s32 n = t + idx;
    if (n >= 3) {
        n = n - 3;
    }
    return (char*)p + n * 0x30 + 0xc;
}
}
