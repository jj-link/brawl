#pragma force_active on
typedef unsigned char u8;

extern "C" void* fn_47_4CCC(u8* base, int index) {
    int i = (*(int*)(base + 8) >> 30) + index;
    if (i >= 1) {
        i--;
    }
    return base + i * 0x38 + 0xc;
}
