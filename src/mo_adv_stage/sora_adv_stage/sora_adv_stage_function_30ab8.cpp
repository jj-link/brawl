#pragma force_active on
extern "C" void* fn_40_30AB8(char* self, int n) {
    int s = *(int*)(self + 8) >> 27;
    int idx = s + n;
    if (idx >= 13) {
        idx -= 13;
    }
    return self + idx * 160 + 12;
}
