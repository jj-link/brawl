#pragma force_active on
extern "C" void* fn_27_D9390(void* base, int index)
{
    int value = *reinterpret_cast<int*>(static_cast<char*>(base) + 8) >> 25;

    if (value + index >= 34)
        index = value + index - 34;
    else
        index = value + index;

    return static_cast<char*>(base) + index * 48 + 12;
}
