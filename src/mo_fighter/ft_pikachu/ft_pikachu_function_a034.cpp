#pragma force_active on
extern "C" void fn_98_A034(char* self, unsigned index) {
    int* table = *(int**)(self + 0x1c);
    table[index] = 0;
}
