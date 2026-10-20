#pragma force_active on
extern "C" void *fn_27_1E7DD4(void *self, int index)
{
    int offset = *(int *)((char *)self + 8) >> 30;
    int adjusted = offset + index;

    if (adjusted < 1)
        goto done;

    adjusted--;

done:
    return (char *)self + adjusted * 12 + 12;
}
