#pragma force_active on
extern "C" void fn_125_B3A8(void* object, void* value, unsigned int index)
{
    void** entries = *reinterpret_cast<void***>(
        reinterpret_cast<char*>(object) + 0x0C);
    entries[index] = value;
}
