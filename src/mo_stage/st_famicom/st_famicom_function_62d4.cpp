#pragma force_active on
extern "C" char* fn_68_62D4(char* self, int index) {
    int adjust = *(int*)(self + 8) >> 30;
    int idx = adjust + index;
    if (idx >= 1) {
        idx -= 1;
    }
    return self + idx * 0xa0 + 0xc;
}
