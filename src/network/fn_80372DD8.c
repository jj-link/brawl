#pragma force_active on
typedef unsigned long size_t;

extern char* strncpy(char* dest, const char* src, size_t n);

void fn_80372DD8(char* dest, const char* src, size_t n) {
    strncpy(dest, src, n);
    dest[n - 1] = '\0';
}
