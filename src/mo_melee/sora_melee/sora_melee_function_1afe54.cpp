#pragma force_active on
extern "C" void* fn_27_1AFE54(char* self, int idx) {
    int n = (*(int*)(self + 8) >> 22) + idx;
    if (n >= 0x11e) {
        n -= 0x11e;
    }
    return self + (n * 4) + 0xc;
}
