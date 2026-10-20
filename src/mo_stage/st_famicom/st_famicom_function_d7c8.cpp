#pragma force_active on
extern "C" {
int fn_68_D7C8(unsigned int *p)
{
    return (int)((p[2] << 8) & 0xF8000000u) >> 28;
}
}
