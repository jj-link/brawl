#pragma force_active on
extern "C" char* fn_74_69C8(char* p, int index) {
    int n = (*(int*)(p + 8) >> 30) + index;
    if (n >= 1) {
        n--;
    }
    return p + n * 0x38 + 0xc;
}
