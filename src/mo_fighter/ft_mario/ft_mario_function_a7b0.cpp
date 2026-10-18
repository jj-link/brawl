#pragma force_active on
extern "C" void fn_91_A7B0(unsigned char* self, unsigned int flags, int index) {
    unsigned int* table = *(unsigned int**)(self + 0x1c);
    table[index] |= flags;
}
