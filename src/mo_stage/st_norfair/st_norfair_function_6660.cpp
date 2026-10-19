#pragma force_active on
extern "C" void* fn_54_6660(char* self, int idx) {
    int sh = (*(int*)(self + 8)) >> 30;
    int n = sh + idx;
    if (n >= 1) {
        n = n - 1;
    }
    return self + 0xC + n * 0x38;
}
