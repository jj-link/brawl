#pragma force_active on
extern "C" void fn_123_A570(void* object, void* value, unsigned int index)
{
    void** entries = *(void***)(static_cast<char*>(object) + 0xC);
    entries[index] = value;
}
