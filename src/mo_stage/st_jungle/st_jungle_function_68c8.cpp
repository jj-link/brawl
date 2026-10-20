#pragma force_active on
extern "C" int fn_51_68C8(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    return (int)(((x >> 19) & 0x1F) << 27) >> 28;
}
