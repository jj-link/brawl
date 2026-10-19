#pragma force_active on
extern "C" {
void* fn_40_1E558(char* p, int n) {
    int idx = (*(int*)(p + 8) >> 26) + n;
    if (idx >= 0x18) {
        idx -= 0x18;
    }
    return p + idx * 0x78 + 0xc;
}
}
