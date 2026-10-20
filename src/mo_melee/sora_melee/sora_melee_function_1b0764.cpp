#pragma force_active on
extern "C" void *fn_27_1B0764(void *this_, int index)
{
    int state = *(int *)((char *)this_ + 8) >> 28;
    int result = state + index;

    if (result >= 4)
        result -= 4;

    return (char *)this_ + result * 0x18 + 0xC;
}
