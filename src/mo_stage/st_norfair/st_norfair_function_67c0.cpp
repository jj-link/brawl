#pragma force_active on
extern "C" char* fn_54_67C0(char* self, int index) {
    int n = (*(int*)(self + 8) >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return self + n * 0x78 + 0xc;
}
