#pragma force_active on
extern "C" void* fn_40_24BB4(char* self, int idx) {
    int t = *(int*)(self + 8) >> 30;
    if (t + idx >= 1) {
        idx = t + idx - 1;
    } else {
        idx = t + idx;
    }
    return self + idx * 0x68 + 0xc;
}
