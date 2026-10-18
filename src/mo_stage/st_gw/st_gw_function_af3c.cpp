#pragma force_active on
extern "C" int fn_63_AF3C(void *p)
{
    unsigned int v = *(unsigned int *)((char *)p + 8);
    unsigned int e = (v << 8) >> 27;
    return (int)(e << 27) >> 28;
}
