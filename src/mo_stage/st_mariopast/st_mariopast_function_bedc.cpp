#pragma force_active on
extern "C" {
int fn_48_BEDC(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    return (int)((x << 12) & 0xFE000000u) >> 26;
}
}
