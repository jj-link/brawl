#pragma force_active on
extern "C" void* fn_27_1E5B00(void* self, int index)
{
    int adjustment = *reinterpret_cast<int*>(static_cast<char*>(self) + 0x18) >> 30;
    int result = adjustment + index;

    if (result >= 1)
        result--;

    return static_cast<char*>(self) + result * 12 + 0x1C;
}
