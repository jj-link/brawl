#pragma force_active on
extern "C" int* fn_27_1AF9F4(void* self, int index)
{
    int value = *(int*)((char*)self + 8);
    int offset = value >> 28;
    int result = offset + index;

    if (result >= 7)
        result -= 7;

    return (int*)((char*)self + 12 + result * 4);
}
