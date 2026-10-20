#pragma force_active on
extern "C" int *fn_27_FBF38(int *p1, int p2)
{
    int index = (p1[6] >> 28) + p2;

    if (index >= 4)
        index -= 4;

    return (int *)((char *)p1 + index * 12 + 0x1C);
}
