#pragma force_active on
typedef unsigned int u32;

extern "C" u32 fn_27_318BEC(char *p, int unused, int x, int i)
{
    int idx = x - *(int *)(p + 0x14);
    char *q = (char *)((int *)p + idx);
    u32 *arr = *(u32 **)(q + 0xd0);
    return arr[i];
}
