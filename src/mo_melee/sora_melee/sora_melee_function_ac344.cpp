#pragma force_active on
extern "C" int *fn_27_AC344(int *ptr, int index)
{
    int field = ptr[2] >> 26;
    int result = field + index;

    if (result >= 25)
        result -= 25;

    return ptr + result + 3;
}
