#pragma force_active on
extern "C" int fn_74_68F0(void *p)
{
    unsigned int v = ((unsigned int *)p)[2];
    unsigned int r = (v << 4) | (v >> 28);
    return (int)(r & 0xE0000000) >> 30;
}
