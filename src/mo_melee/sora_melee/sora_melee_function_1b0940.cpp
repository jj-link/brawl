#pragma force_active on
extern "C" void* fn_27_1B0940(void* p, int index)
{
    int value = ((int*)p)[2] >> 28;
    int result = value + index;
    if (result >= 4)
        result -= 4;
    return (char*)p + result * 16 + 12;
}
