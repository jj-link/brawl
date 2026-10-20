#pragma force_active on
extern "C" {
int fn_27_295720(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    unsigned int r = (x << 5) | (x >> 27);
    return (int)(r & 0xFC000000u) >> 27;
}
}
