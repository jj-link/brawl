#pragma force_active on
extern "C" void* fn_27_1B06C4(void* self, int idx)
{
    int t = ((int*)self)[2] >> 27;
    int n = t + idx;
    if (n >= 12) {
        n -= 12;
    }
    return (char*)self + n * 0x34 + 0xC;
}
