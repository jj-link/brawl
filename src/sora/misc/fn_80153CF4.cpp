#pragma force_active on

extern "C" unsigned char fn_80153CF4(void** p) {
    if (*p == 0) {
        return 4;
    }
    return ((unsigned char*)*p)[0x15];
}
