#pragma force_active on
extern "C" void* fn_27_10E7E0(void* object, int index)
{
    int offset = *(int*)((char*)object + 0x18) >> 27;
    int result = offset + index;

    if (result >= 8)
        result -= 8;

    return (char*)object + 0x1C + result * 0xC;
}
