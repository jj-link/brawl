#pragma force_active on
extern "C" void* fn_40_30D78(void* object, int index)
{
    int value = (*(int*)((char*)object + 8) >> 27) + index;
    if (value >= 13)
        value -= 13;

    return (char*)object + value * 0x90 + 0x0C;
}
