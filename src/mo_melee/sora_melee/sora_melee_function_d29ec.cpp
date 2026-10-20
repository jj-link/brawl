#pragma force_active on
extern "C" int fn_27_D29EC(void *p)
{
    unsigned int x = ((unsigned int *)p)[2];
    unsigned int r = ((x << 6) | (x >> 26)) & 0xF0000000;
    return (int)r >> 29;
}
