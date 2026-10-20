#pragma force_active on
extern "C" int fn_68_64EC(const unsigned int *p)
{
    return (int)((p[2] << 4) & 0xE0000000u) >> 30;
}
