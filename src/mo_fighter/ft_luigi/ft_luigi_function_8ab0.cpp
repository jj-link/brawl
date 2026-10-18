#pragma force_active on
extern "C" void fn_99_8AB0(unsigned char* object, unsigned int flags, unsigned int index) {
    unsigned int* table = *(unsigned int**)(object + 0x1c);
    table[index] |= flags;
}
