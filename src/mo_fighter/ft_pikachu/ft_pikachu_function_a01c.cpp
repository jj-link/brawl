#pragma force_active on
extern "C" void fn_98_A01C(char* self, unsigned mask, unsigned index) {
    unsigned* flags = *(unsigned**)(self + 0x1c);
    flags[index] &= ~mask;
}
