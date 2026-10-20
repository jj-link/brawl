#pragma force_active on
extern "C" int* fn_27_1AF79C(int* object, int index)
{
    int offset = object[2] >> 22;
    int result = offset + index;
    if (result >= 0x12F)
        result -= 0x12F;
    return reinterpret_cast<int*>(reinterpret_cast<char*>(object) + result * 4 + 0xC);
}
