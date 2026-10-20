#pragma force_active on
extern "C" void* fn_27_50D4C(void* p, int i)
{
    int value = *(int*)((char*)p + 0x18);
    int index = (value >> 23) + i;

    if (index >= 0xFF)
        index -= 0xFF;

    return (char*)p + index * 12 + 0x1C;
}
