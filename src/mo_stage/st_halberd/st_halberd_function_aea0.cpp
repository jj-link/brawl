#pragma force_active on
extern "C" {
int fn_57_AEA0(unsigned int *p)
{
    unsigned int v = p[2];
    unsigned int r = (v << 8) | (v >> 24);
    r &= 0xF8000000;
    return (int)r >> 28;
}
}
