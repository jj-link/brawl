#pragma force_active on
extern "C" void* fn_27_D9480(void* p, int index)
{
    int packed = *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 8);
    int slot = (packed >> 26) + index;
    if (slot >= 28)
        slot -= 28;
    return reinterpret_cast<char*>(p) + slot * 0x30 + 0x0C;
}
