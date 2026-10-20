#pragma force_active on
extern "C" int fn_48_B4E0(void *p)
{
    unsigned int w = *(unsigned int *)((char *)p + 8);
    int v = (int)(((w << 9) | (w >> 23)) & 0xFFC00000);
    return v >> 23;
}
