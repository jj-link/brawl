#pragma force_active on
extern "C" int fn_27_19A258(void *p)
{
    unsigned int x = ((unsigned int *)p)[2];
    unsigned int f = (x >> 21) & 0x3F;
    return (int)(f << 26) >> 27;
}
