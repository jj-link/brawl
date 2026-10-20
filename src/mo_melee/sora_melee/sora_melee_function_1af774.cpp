#pragma force_active on
extern "C" int *fn_27_1AF774(int *base, int index)
{
    int offset = base[2] >> 22;
    int result = offset + index;

    if (result >= 0x131)
        result -= 0x131;

    return base + result + 3;
}
