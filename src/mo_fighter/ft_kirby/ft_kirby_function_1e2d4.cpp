#pragma force_active on
extern "C" void* fn_96_1E2D4(void* obj, int index) {
    int i = (((int*)obj)[2] >> 28) + index;
    if (i >= 4) {
        i -= 4;
    }
    return (char*)obj + i * 0x60 + 0xc;
}
