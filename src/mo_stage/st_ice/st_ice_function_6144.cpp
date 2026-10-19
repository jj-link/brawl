#pragma force_active on
extern "C" char* fn_62_6144(char* self, int index) {
    int n = (*(int*)(self + 8) >> 29) + index;
    if (n >= 2) {
        n -= 2;
    }
    return self + n * 0x90 + 0xc;
}
