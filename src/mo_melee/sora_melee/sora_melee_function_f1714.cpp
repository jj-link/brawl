#pragma force_active on
extern "C" int* fn_27_F1714(void* object, int index)
{
    int offset = *(int*)((char*)object + 0x18) >> 29;
    int result = offset + index;
    if (result >= 2)
        result -= 2;
    return (int*)((char*)object + result * 12 + 0x1C);
}
