#pragma force_active on
extern "C" unsigned char fn_800D81AC(unsigned char *tab, int index, unsigned char *out)
{
    unsigned char *p = tab + (index << 3);
    *out = p[0x4d];
    return p[0x4c];
}
