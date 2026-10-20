#pragma force_active on
extern "C" int* fn_27_F16EC(int* base, int index)
{
    int shift = base[6] >> 29;
    int result = shift + index;

    if (result < 2)
        goto done;

    result -= 2;

done:
    return (int*)((char*)base + result * 12 + 0x1C);
}
