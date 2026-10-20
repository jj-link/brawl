#pragma force_active on
typedef int s32;

extern "C" void* fn_27_1D04E8(void* self, s32 idx)
{
    s32 n = ((s32*)self)[2];
    n = (n >> 25) + idx;
    if (n >= 0x21) {
        n -= 0x21;
    }
    return (char*)self + 0xc + n * 12;
}
