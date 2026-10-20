#pragma force_active on
extern "C" void fn_1_832C(char* p, unsigned int a, unsigned int b) {
    char* s = *(char**)(p + 0x35c);
    char* o = *(char**)(s + 8);
    *(unsigned int*)(o + 0x40) = a;
    *(unsigned int*)(o + 0x44) = b;
}
