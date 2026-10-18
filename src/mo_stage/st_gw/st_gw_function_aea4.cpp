#pragma force_active on
extern "C" int fn_63_AEA4(int *p)
{
    int v = (p[2] << 4) & 0xE0000000;
    return v >> 30;
}
