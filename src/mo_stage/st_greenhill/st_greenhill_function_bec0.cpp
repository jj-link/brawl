#pragma force_active on
extern "C" {
int fn_72_BEC0(int *p)
{
    unsigned int x = (unsigned int)p[2];
    return (int)((x << 3 | x >> 29) & 0xF0000000) >> 29;
}
}
