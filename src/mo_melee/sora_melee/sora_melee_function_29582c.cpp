#pragma force_active on
extern "C" int* fn_27_29582C(int* object, int index)
{
    int result = (object[2] >> 26) + index;
    if (result >= 0x10)
        result -= 0x10;
    return object + result + 3;
}
