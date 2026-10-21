#pragma force_active on

extern "C" void fn_800DCF38(unsigned char* p, int x) {
    unsigned char* q = *(unsigned char**)(p + 0x94);
    if (q != 0) {
        (q + x)[0x37] = 1;
        (q + x)[0x32] = 0;
        *(int*)(q + 0x40) = x;
    }
}
