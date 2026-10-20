#pragma force_active on
extern "C" int fn_27_295CA4(unsigned int *p)
{
    unsigned int v = p[2];
    int y = (int)(((v >> 22) & 0xF) << 28);
    return y >> 29;
}
