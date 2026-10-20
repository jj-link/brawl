#pragma force_active on
extern "C" void* fn_27_1B0084(void* object, int index)
{
    int value = *reinterpret_cast<int*>(static_cast<char*>(object) + 8) >> 29;
    int result = value + index;
    if (result >= 3)
        result -= 3;
    return static_cast<char*>(object) + result * 20 + 12;
}
