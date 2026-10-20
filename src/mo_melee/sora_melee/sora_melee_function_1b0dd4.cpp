#pragma force_active on
extern "C" char* fn_27_1B0DD4(char* self, int idx) {
    int v = *(int*)(self + 8) >> 28;
    int n = v + idx;
    idx = (n >= 4) ? n - 4 : n;
    return self + idx * 0x5c + 0xc;
}
