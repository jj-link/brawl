#pragma force_active on
extern "C" {
void fn_2_35B50(char* p) {
    char* q = *(char**)(p + 0x40);
    int v = *(int*)(q + 0x1d0);
    if (v > 0) {
        *(int*)(q + 0x1d0) = v - 1;
        return;
    }
    if (v != 0) {
        return;
    }
    *(int*)(q + 0x1d0) = v - 1;
    char* r = *(char**)(*(char**)(p + 0x40));
    unsigned char b = r[0xd8];
    r[0xd8] = (char)(b & ~0x20);
}
}
