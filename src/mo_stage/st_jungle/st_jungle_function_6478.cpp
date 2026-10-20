#pragma force_active on
extern "C" int fn_51_6478(void *p)
{
    unsigned int v = *(unsigned int *)((char *)p + 8);
    unsigned int r = ((v << 4) | (v >> 28)) & 0xE0000000u;
    return (int)r >> 30;
}
