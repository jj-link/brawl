#pragma force_active on
extern "C" char* fn_72_5118(char* self, int index) {
    int n = (*(int*)(self + 0x8) >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return self + n * 0x68 + 0xc;
}
