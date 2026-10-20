#pragma force_active on
extern "C" char* fn_27_D9570(char* p, int idx) {
    int v = *(int*)(p + 8);
    int i = (v >> 26) + idx;
    if (i >= 0x16) {
        i -= 0x16;
    }
    return p + i * 0x30 + 0xc;
}
