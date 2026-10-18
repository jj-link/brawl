#pragma force_active on
extern "C" void* fn_98_A1A8(void* object, unsigned index) {
    void** entries = *reinterpret_cast<void***>(static_cast<char*>(object) + 0xC);
    return entries[index];
}
