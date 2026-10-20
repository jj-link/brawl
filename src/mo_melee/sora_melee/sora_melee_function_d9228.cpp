#pragma force_active on
extern "C" char* fn_27_D9228(char* r3, int r4) {
    int r0 = *(int*)(r3 + 8);
    r0 = r0 >> 25;
    int s = r0 + r4;
    if (s >= 0x3d) {
        s -= 0x3d;
    }
    return r3 + s * 0x30 + 0xc;
}
