#pragma force_active on
extern "C" int fn_27_19D488(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    return (int)((x << 10) & 0xFC000000u) >> 27;
}
