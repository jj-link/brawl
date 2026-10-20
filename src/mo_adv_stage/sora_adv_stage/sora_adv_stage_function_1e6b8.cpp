#pragma force_active on
extern "C" int* fn_40_1E6B8(void* object, int index)
{
    int value = (*(int*)((char*)object + 8) >> 28) + index;
    if (value >= 6) {
        value -= 6;
    }
    return (int*)((char*)object + 12 + value * 8);
}
