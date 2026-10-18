#pragma force_active on
extern "C" void fn_98_A180(char* self, int delta, unsigned index) {
    int* table = *(int**)(self + 0xc);
    table[index] += delta;
}
