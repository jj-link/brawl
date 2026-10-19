#pragma force_active on
extern "C" void* fn_51_DA74(void* object, int index)
{
    int offset = *(int*)((char*)object + 8) >> 29;
    int result = offset + index;

    if (result >= 2)
        result -= 2;

    return (char*)object + result * 0x68 + 0x0C;
}
