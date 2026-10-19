#pragma force_active on
extern "C" bool fn_118_A3C0(void* object, unsigned int mask, unsigned int index) {
    unsigned int value = *reinterpret_cast<unsigned int*>(
        *reinterpret_cast<unsigned int**>(static_cast<unsigned char*>(object) + 0x1C) + index);
    return (mask & value) != 0;
}
