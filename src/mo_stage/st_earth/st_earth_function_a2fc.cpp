#pragma force_active on
extern "C" char* fn_66_A2FC(char* self, int index) {
    int n = (*(int*)(self + 8) >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return self + n * 0xa0 + 0xc;
}
