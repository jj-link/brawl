#pragma force_active on
extern "C" int fn_61_A648(int *p)
{
    unsigned int x = (unsigned int)p[2];
    return (int)(((x << 2) | (x >> 30)) & 0xE0000000) >> 30;
}
