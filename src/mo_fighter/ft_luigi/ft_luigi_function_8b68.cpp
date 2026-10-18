#pragma force_active on
extern "C" void fn_99_8B68(unsigned char* self, int index) {
    int* table = *(int**)(self + 0xc);
    table[index] = table[index] - 1;
}
