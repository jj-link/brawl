#pragma force_active on
extern "C" int* fn_27_1AF864(int* base, int index)
{
    int offset = (int)(*(int*)((char*)base + 8) >> 22);
    int result = offset + index;

    if (result >= 0x123)
        result -= 0x123;

    return (int*)((char*)base + 12 + result * 4);
}
