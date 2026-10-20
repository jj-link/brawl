#pragma force_active on
extern "C" int fn_48_3F10(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    return (int)((x << 8 | x >> 24) & 0xF8000000) >> 28;
}
