#pragma force_active on
extern "C" void *fn_27_D9818(void *self, int index)
{
    int offset = *(int *)((char *)self + 8) >> 30;
    int adjusted = offset + index;
    if (adjusted >= 1)
        adjusted -= 1;
    return (char *)self + adjusted * 0x38 + 0x0C;
}
