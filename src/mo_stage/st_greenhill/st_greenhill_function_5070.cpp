#pragma force_active on
extern "C" int fn_72_5070(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    return ((int)((x << 4) & 0xE0000000)) >> 30;
}
