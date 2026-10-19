#pragma force_active on
extern "C" char* fn_62_620C(char* self, int idx) {
    int v = *(int*)(self + 8) >> 28;
    int n = v + idx;
    if (n >= 7) {
        n -= 7;
    }
    return self + n * 8 + 12;
}
