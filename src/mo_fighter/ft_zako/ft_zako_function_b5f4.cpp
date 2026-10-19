#pragma force_active on
extern "C" void fn_126_B5F4(unsigned char* object, const unsigned char* data) {
    for (int i = 0; i < 2; i++) {
        *(unsigned int*)(object + 0x10 + i * 8) = *(const unsigned int*)(data + 0x7C);
    }
}
