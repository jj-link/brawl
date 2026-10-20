#pragma force_active on
extern "C" void *fn_27_D9B88(void *arg0, int arg1)
{
    int index = *(int *)((char *)arg0 + 8) >> 29;
    int result = index + arg1;

    if (result >= 2)
        result -= 2;

    return (char *)arg0 + result * 0x48 + 0xC;
}
