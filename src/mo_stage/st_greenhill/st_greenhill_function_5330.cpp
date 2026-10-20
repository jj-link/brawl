#pragma force_active on
extern "C" int fn_72_5330(void *p)
{
    unsigned int v = *(unsigned int *)((char *)p + 8);
    return (int)((v << 8) & 0xF8000000) >> 28;
}
