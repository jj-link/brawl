#pragma force_active on
extern "C" void fn_27_CAF08(unsigned char* self) {
    unsigned int* flags = (unsigned int*)(self + 8);
    *flags &= ~0x10000u;
}
