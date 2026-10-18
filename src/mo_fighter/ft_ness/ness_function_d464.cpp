#pragma force_active on
extern "C" void fn_101_D464(unsigned char* self, unsigned int index) {
    int* table = *reinterpret_cast<int**>(self + 0xC);
    table[index] = table[index] - 1;
}
