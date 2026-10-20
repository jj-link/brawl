#pragma force_active on
extern "C" void* fn_27_2645C0(char* p, int i)
{
    int d = *(int*)(p + 0x18) >> 30;
    int t = d + i;
    i = (t >= 1) ? t - 1 : t;
    return p + i * 12 + 0x1c;
}
