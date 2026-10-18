#pragma force_active on
extern "C" void fn_98_A168(char* obj, int value, unsigned index) {
    int* table = *(int**)(obj + 0xc);
    table[index] -= value;
}
