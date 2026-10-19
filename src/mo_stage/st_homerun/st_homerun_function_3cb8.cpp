#pragma force_active on
extern "C" void fn_88_3CB8(char *r3, void **r4, void **r5, int r6) {
    if (r6 == 0x4f) {
        *r4 = r3 + 0x5f0;
        *r5 = r3 + 0x670;
        return;
    }
    if (r6 != 0x21) {
        return;
    }
    *r4 = r3 + 0x6f0;
    *r5 = r3 + 0x770;
}
