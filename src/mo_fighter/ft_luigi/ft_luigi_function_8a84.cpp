#pragma force_active on
extern "C" void fn_99_8A84(unsigned char* object, unsigned int mask, int index) {
    unsigned int* bits = *(unsigned int**)(object + 0x1c);
    bits[index] &= ~mask;
}
