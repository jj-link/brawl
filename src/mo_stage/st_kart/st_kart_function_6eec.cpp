#pragma force_active on
extern "C" int fn_49_6EEC(void *p)
{
    unsigned int v = *(unsigned int *)((char *)p + 8);
    return (int)((v << 4) & 0xF8000000) >> 28;
}
