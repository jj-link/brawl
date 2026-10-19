#pragma force_active on
extern "C" char* fn_48_BBFC(char* self, int index) {
    int i = (*(int*)(self + 8) >> 26) + index;
    if (i >= 25) {
        i -= 25;
    }
    return self + i * 0x78 + 0xc;
}
