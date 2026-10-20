#pragma force_active on
extern "C" {
int fn_70_92F4(void *p)
{
    unsigned int w = *(unsigned int *)((char *)p + 8);
    return (int)((w << 8) & 0xF8000000) >> 28;
}
}
