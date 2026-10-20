#pragma force_active on
extern "C" int fn_49_6BC8(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    int r = (int)((x << 4) & 0xE0000000u);
    return r >> 30;
}
