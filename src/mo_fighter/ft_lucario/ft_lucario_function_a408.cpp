#pragma force_active on
extern "C" void fn_118_A408(unsigned char* self, unsigned int bits, unsigned int idx) {
    unsigned int* arr = *(unsigned int**)(self + 0x1c);
    arr[idx] |= bits;
}
