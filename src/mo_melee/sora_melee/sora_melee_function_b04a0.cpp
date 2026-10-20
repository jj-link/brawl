#pragma force_active on
extern "C" void* fn_27_B04A0(void* object, int index)
{
    int shift = *(int*)((char*)object + 8) >> 27;
    int sum = shift + index;

    if (sum >= 8)
        sum -= 8;

    return (char*)object + sum * 12 + 12;
}
