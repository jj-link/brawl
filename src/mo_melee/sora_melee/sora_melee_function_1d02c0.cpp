#pragma force_active on
extern "C" {
void* fn_27_1D02C0(void* p, int idx)
{
    int i = (*(int*)((char*)p + 8) >> 25) + idx;
    if (i >= 40) {
        i -= 40;
    }
    return (char*)p + i * 12 + 12;
}
}
