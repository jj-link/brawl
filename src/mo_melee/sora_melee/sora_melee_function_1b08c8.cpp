#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" void* fn_27_1B08C8(void* self, s32 idx)
{
    s32 t = (*(s32*)((char*)self + 8)) >> 28;
    s32 n = t + idx;
    if (n >= 4) {
        n -= 4;
    }
    return (char*)self + (n << 4) + 0xc;
}
