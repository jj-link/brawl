#pragma force_active on
extern "C" void *fn_27_D96D8(void *p, int index)
{
    int count = *(int *)((char *)p + 8) >> 30;
    int result = count + index;
    if (result >= 1)
        result -= 1;
    return (char *)p + result * 0xB8 + 0xC;
}
