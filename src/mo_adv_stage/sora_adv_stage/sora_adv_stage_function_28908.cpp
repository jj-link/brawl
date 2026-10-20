#pragma force_active on
extern "C" int fn_40_28908(void *self)
{
    unsigned int v = *(unsigned int *)((char *)self + 8);
    return (int)((v << 4) & 0xE0000000u) >> 30;
}
