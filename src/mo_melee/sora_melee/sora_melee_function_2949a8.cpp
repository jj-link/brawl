#pragma force_active on
extern "C" int* fn_27_2949A8(int* object, int index)
{
    int value = (object[6] >> 26) + index;

    if (value >= 30)
        value -= 30;

    return reinterpret_cast<int*>(reinterpret_cast<char*>(object) + value * 12 + 0x1C);
}
