#pragma force_active on
extern "C" int fn_71_9F08(void *p)
{
    unsigned int v = *(unsigned int *)((char *)p + 8);
    unsigned int r = (v << 4) | (v >> 28);
    return (int)(r & 0xE0000000) >> 30;
}
