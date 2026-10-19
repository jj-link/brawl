#pragma force_active on
extern "C" {
void* fn_40_28918(char* self, int idx) {
    int r0 = *(int*)(self + 8) >> 30;
    int n = r0 + idx;
    if (n < 1) {
        n = n;
    } else {
        n = n - 1;
    }
    return self + n * 0x90 + 0xc;
}
}
