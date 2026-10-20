#pragma force_active on
extern "C" int fn_27_1D06AC(void *p)
{
    unsigned int v = *(unsigned int *)((char *)p + 8);
    unsigned int t = ((v << 4) | (v >> 28)) & 0xF8000000;
    return (int)t >> 28;
}
