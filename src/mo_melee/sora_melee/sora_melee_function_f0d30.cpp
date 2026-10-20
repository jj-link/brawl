#pragma force_active on
extern "C" int* fn_27_F0D30(void* object, int index)
{
    int adjustment = *(int*)((char*)object + 0x18) >> 30;
    int result = adjustment + index;
    if (result >= 1)
        result--;
    return (int*)((char*)object + result * 12 + 0x1C);
}
