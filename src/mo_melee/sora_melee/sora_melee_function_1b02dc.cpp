#pragma force_active on
extern "C" {
void* fn_27_1B02DC(char* self, int idx) {
    int n = (*(int*)(self + 8) >> 27) + idx;
    if (n >= 9) {
        n -= 9;
    }
    return self + n * 0x60 + 0xC;
}
}
