#pragma force_active on
extern "C" void* fn_27_1AFC74(char* self, int idx) {
    int n = *(int*)(self + 8) >> 22;
    int t = n + idx;
    idx = (t >= 0x139) ? t - 0x139 : t;
    return self + (idx * 4) + 0xc;
}
