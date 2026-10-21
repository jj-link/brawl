#pragma force_active on
extern "C" int fn_51_DA64(int *p)
{
    unsigned int x = (unsigned int)p[2];
    unsigned int t = (x << 6) & 0xF0000000;
    return (int)t >> 29;
}
