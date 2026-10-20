#pragma force_active on
extern "C" void* fn_27_1B0D5C(void* p, int index)
{
    int count = *(int*)((char*)p + 8) >> 27;
    int slot = count + index;
    if (slot >= 10)
        slot -= 10;
    return (char*)p + slot * 0x8C + 0xC;
}
