#pragma force_active on
void fn_801D7974(int, int, int);

unsigned int fn_801D7A38(int arg0, int arg1, int arg2) {
    unsigned int n = ((unsigned int)arg2 + 0x1F) >> 5;
    unsigned int blocks = (n + 0x7F) >> 7;
    int src = arg1;
    int dst = arg0;
    while (n != 0) {
        if (n < 0x80) {
            fn_801D7974(dst, src, (int)n);
            n = 0;
        } else {
            fn_801D7974(dst, src, 0);
            n -= 0x80;
            dst += 0x1000;
            src += 0x1000;
        }
    }
    return blocks;
}
