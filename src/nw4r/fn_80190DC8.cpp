#pragma force_active on
extern "C" void* fn_80190DC8(void** base, int index)
{
    void* val = *base;
    if (val != 0 && index >= 0 && index <= 7)
    {
        return static_cast<char*>(val) + index * 0xC + 4;
    }
    return 0;
}
