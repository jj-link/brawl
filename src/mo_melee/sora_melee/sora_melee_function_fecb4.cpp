#pragma force_active on
extern "C" int *fn_27_FECB4(int *p, int index)
{
    int offset = p[2] >> 25;
    int result = offset + index;
    if (result >= 37)
        result -= 37;
    return (int *)((char *)p + result * 12 + 12);
}
