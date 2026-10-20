#pragma force_active on
extern "C" int fn_51_D9CC(char *p)
{
    unsigned int x = *(unsigned int *)(p + 8);
    return (int)((x << 6) & 0xF0000000) >> 29;
}
