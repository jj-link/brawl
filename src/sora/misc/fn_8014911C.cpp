#pragma force_active on
extern "C" unsigned char fn_8014911C(void* a1) {
    unsigned char val = ((unsigned char*)a1)[0x34AA];
    ((unsigned char*)a1)[0x34AA] = 0;
    return val;
}
