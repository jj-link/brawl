#pragma force_active on
extern "C" {
int fn_51_6864(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    return (int)((x << 4) & 0xF8000000u) >> 28;
}
}
