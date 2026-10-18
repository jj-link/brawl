#pragma force_active on
extern "C" void fn_112_A9E4(unsigned char* self, unsigned int mask, unsigned int index) {
    unsigned int* flags = *(unsigned int**)(self + 0x1c);
    flags[index] |= mask;
}
