#pragma force_active on
extern "C" {
int fn_49_6FB4(unsigned int *p)
{
    unsigned int w = p[2];
    return (int)((w << 4) & 0xF8000000u) >> 28;
}
}
