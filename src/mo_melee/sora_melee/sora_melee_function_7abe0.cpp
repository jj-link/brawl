#pragma force_active on
extern "C" int* fn_27_7ABE0(int* p, int index)
{
    int value = p[2] >> 26;
    int result = value + index;

    if (result >= 0x18)
        result -= 0x18;

    return (int*)((char*)p + result * 4 + 0x0C);
}
