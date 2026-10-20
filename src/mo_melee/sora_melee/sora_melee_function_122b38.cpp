#pragma force_active on
extern "C" {
int fn_27_122B38(void *p)
{
    int x = *(int *)((char *)p + 8);
    return (int)((x << 6) & 0xFE000000) >> 26;
}
}
