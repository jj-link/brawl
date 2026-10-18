#pragma force_active on
extern "C" void fn_93_B254(unsigned char* self, unsigned int bits, unsigned int index) {
    unsigned int* arr = *(unsigned int**)(self + 0x1c);
    arr[index] |= bits;
}
