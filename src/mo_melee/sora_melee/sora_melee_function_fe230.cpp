#pragma force_active on
extern "C" int fn_27_FE230(const unsigned int *p)
{
    return (int)((*(const unsigned int *)((const char *)p + 8) << 6) & 0xFE000000u) >> 26;
}
