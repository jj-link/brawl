#pragma force_active on
extern "C" void fn_120_9B94(void* object, void* value, unsigned int index)
{
    void** entries = *reinterpret_cast<void***>(
        reinterpret_cast<unsigned char*>(object) + 0x0C);
    entries[index] = value;
}
