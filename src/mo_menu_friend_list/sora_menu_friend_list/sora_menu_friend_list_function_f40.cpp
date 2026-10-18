#pragma force_active on
extern "C" {
char* strcpy(char* dst, const char* src);
}

extern "C" char* fn_14_F40(char* base, char* dst, int idx) {
    return strcpy(dst, base + idx * 0x51 + 0x2325);
}
