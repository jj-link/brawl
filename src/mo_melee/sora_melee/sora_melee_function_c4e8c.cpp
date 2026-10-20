#pragma force_active on
extern "C" void* fn_27_C4E8C(char* self, int idx) {
    int n = (*(int*)(self + 0x18) >> 30) + idx;
    if (n < 1) {
    } else {
        n -= 1;
    }
    return self + n * 12 + 0x1c;
}
