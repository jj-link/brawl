#pragma force_active on
extern "C" int fn_120_9E7C();

extern "C" int fn_120_9E88(void* fighter, int, int parameter, int element) {
    const unsigned int base = reinterpret_cast<unsigned int>(fighter);
    const unsigned int fieldAddress =
        base - 0x10000 + fn_120_9E7C() * 0x38;
    const unsigned int* table =
        *reinterpret_cast<const unsigned int* const*>(
            fieldAddress + parameter * 4 - 0x7540);
    return reinterpret_cast<const int*>(table)[element];
}
