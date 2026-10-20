#pragma force_active on
extern "C" int fn_51_591C(int *p)
{
    unsigned int x = (unsigned int)p[2];
    unsigned int r = (x << 2) | (x >> 30);
    return (int)(r & 0xE0000000) >> 30;
}
