#pragma force_active on
extern "C" int fn_74_6B7C(void *r3)
{
    unsigned int v = *(unsigned int *)((char *)r3 + 8);
    unsigned int r = (v << 4) | (v >> 28);
    return (int)(r & 0xF8000000u) >> 28;
}
