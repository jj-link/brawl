#pragma force_active on
extern "C" char* fn_61_E798(char* self, int index) {
    int idx = (*(int*)(self + 8) >> 29) + index;
    if (idx >= 2) {
        idx -= 2;
    }
    return self + idx * 0x90 + 0xc;
}
