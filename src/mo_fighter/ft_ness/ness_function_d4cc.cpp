#pragma force_active on
extern "C" void fn_101_D4CC(unsigned char* self, int value, int index) {
    int* table = *reinterpret_cast<int**>(self + 0xC);
    table[index] -= value;
}
