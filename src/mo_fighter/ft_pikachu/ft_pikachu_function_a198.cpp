#pragma force_active on
extern "C" void fn_98_A198(void* object, void* value, int index)
{
    void** entries = *reinterpret_cast<void***>(
        static_cast<char*>(object) + 0x0C);
    entries[index] = value;
}
