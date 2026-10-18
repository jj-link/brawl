#pragma force_active on
extern "C" void fn_99_8A9C(unsigned char* self, int index) {
    void** table = *(void***)(self + 0x1c);
    table[index] = 0;
}
