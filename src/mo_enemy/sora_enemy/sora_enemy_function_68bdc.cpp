#pragma force_active on
extern "C" {
void *fn_41_68BDC(char *p, int n) {
    if (n == 5) {
        return p + 0xFC;
    }
    if (n == 4) {
        return p + 0xD0;
    }
    if (n == 3) {
        return p + 0xA4;
    }
    if (n == 2) {
        return p + 0x78;
    }
    if (n == 1) {
        return p + 0x4C;
    }
    if (n == 0) {
        return p + 0x20;
    }
    return 0;
}
}
