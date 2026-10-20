#pragma force_active on
extern "C" int fn_40_24B0C(int *p)
{
    int v = (int)(((unsigned int)p[2] << 4) & 0xE0000000u);
    return v >> 30;
}
