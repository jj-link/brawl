#pragma force_active on
typedef int s32;

extern "C" {
void* fn_27_1B0E24(void* p, s32 idx)
{
    s32 t = ((s32*)p)[2];
    t = (t >> 29) + idx;
    if (t >= 3) {
        t -= 3;
    }
    return (char*)p + t * 0xb8 + 0xc;
}
}
