#pragma force_active on
extern "C" int fn_27_390468(void *p)
{
    unsigned int x = ((unsigned int *)p)[2];
    unsigned int r = ((x << 6) | (x >> 26)) & 0xFE000000u;
    return ((int)r) >> 26;
}
