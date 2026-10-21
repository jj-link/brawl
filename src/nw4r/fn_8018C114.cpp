#pragma force_active on
extern "C" int strncmp(const char* s1, const char* s2, unsigned long n);

extern "C" bool fn_8018C114(const char* s1, const char* s2) {
    return strncmp(s1, s2, 0x14) == 0;
}
