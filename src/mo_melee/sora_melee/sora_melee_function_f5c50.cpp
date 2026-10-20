#pragma force_active on
extern "C" int* fn_27_F5C50(int* object, int index)
{
    int value = (object[6] >> 29) + index;
    if (value >= 2)
        value -= 2;
    return reinterpret_cast<int*>(reinterpret_cast<char*>(object) + value * 12 + 0x1C);
}
