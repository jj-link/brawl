#pragma force_active on
extern "C" void* fn_27_1C1890(void* self, int index)
{
    int field = *(int*)((char*)self + 0x18);
    int offset = field >> 27;
    int result = offset + index;
    if (result >= 8)
        result -= 8;
    return (char*)self + 0x1C + result * 12;
}
