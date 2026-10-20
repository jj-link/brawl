#pragma force_active on
extern "C" int fn_68_65B4(unsigned char *p)
{
    unsigned int x = *(unsigned int *)(p + 8);
    return (int)((x >> 19) & 0x1F) << 27 >> 28;
}
