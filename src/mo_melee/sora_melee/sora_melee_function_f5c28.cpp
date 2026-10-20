#pragma force_active on
extern "C" void* fn_27_F5C28(void* object, int index)
{
    int flags = *reinterpret_cast<int*>(static_cast<char*>(object) + 0x18);
    int value = (flags >> 29) + index;

    if (value >= 2)
        value -= 2;

    return static_cast<char*>(object) + value * 0xC + 0x1C;
}
