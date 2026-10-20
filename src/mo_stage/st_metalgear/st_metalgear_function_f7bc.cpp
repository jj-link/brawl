#pragma force_active on
extern "C" int fn_71_F7BC(void *p)
{
    unsigned int w = *(unsigned int *)((char *)p + 8);
    return (int)((w << 8) & 0xF8000000u) >> 28;
}
