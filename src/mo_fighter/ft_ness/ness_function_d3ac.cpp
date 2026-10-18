#pragma force_active on
extern "C" void fn_101_D3AC(unsigned char* self, unsigned int flags, unsigned int index) {
    unsigned int* table = *reinterpret_cast<unsigned int**>(self + 0x1c);
    table[index] |= flags;
}
