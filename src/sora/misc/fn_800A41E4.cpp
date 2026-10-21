#pragma force_active on
extern "C" void fn_800A41E4(void *dst, const void *src)
{
    const unsigned int *s = (const unsigned int *)src;
    unsigned int *d = (unsigned int *)dst;
    d[0] = s[0x11C / 4];
    d[1] = s[0x120 / 4];
    d[2] = s[0x124 / 4];
}
