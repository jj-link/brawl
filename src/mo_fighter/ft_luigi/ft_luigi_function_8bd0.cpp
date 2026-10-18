#pragma force_active on
extern "C" void fn_99_8BD0(unsigned char* self, int value, unsigned int index) {
    int* table = *(int**)(self + 0xc);
    table[index] -= value;
}
