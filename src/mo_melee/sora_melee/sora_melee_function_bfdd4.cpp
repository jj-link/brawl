#pragma force_active on
extern "C" void fn_27_BFDD4(char* p, unsigned int n, float a, float b) {
    if (n == 1) {
        p += 0xb8;
    } else {
        p += 0x30;
    }
    *(float*)(p + 0x78) = a;
    *(float*)(p + 0x7c) = b;
}
