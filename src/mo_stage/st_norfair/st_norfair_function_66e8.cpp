#pragma force_active on
extern "C" int fn_54_66E8(void *p)
{
    unsigned int v = *(unsigned int *)((char *)p + 8);
    return (int)(((v << 6) | (v >> 26)) & 0xF0000000u) >> 29;
}
