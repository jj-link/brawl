#pragma force_active on
extern "C" void* fn_11_7DCC(char* base, int a, int b) {
    char* p = base + (a << 4);
    return *(char**)(p + 0x54) + b * 0x18;
}
