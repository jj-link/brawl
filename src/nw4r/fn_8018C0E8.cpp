#pragma force_active on
extern "C" int strncmp(const char* s1, const char* s2, unsigned long n);

extern "C" bool fn_8018C0E8(const char* a, const char* b) {
    return strncmp(a, b, 0x10) == 0;
}
