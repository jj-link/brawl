#pragma force_active on
extern "C" void fn_27_25088(void *dst, const void *src)
{
    const unsigned int *s = (const unsigned int *)src;
    unsigned int *d = (unsigned int *)dst;
    d[0] = s[3];
    d[1] = s[4];
    d[2] = s[5];
}
