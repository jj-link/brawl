#pragma force_active on
extern "C" int fn_52_75D0(unsigned int *p)
{
    unsigned int x = p[2];
    int r = (int)((x << 4) & 0xE0000000u);
    return r >> 30;
}
