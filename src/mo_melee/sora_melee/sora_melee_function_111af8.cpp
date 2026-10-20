#pragma force_active on
extern "C" unsigned int fn_27_111AF8(void** arg) {
    unsigned int value = *reinterpret_cast<unsigned char*>(
        static_cast<char*>(*arg) + 0x48E);
    unsigned int bit = (value >> 7) & 1;
    unsigned int negated = 0u - bit;
    return (negated | bit) >> 31;
}
