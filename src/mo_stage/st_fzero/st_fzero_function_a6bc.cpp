#pragma force_active on
extern "C" char* fn_61_A6BC(char* self, int index) {
    int n = (*(int*)(self + 8) >> 30) + index;
    if (n >= 1) {
        n = n - 1;
    }
    return self + n * 0x78 + 0xC;
}
