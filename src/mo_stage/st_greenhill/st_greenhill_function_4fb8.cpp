#pragma force_active on
extern "C" char* fn_72_4FB8(char* self, int index) {
    int idx = (*(int*)(self + 8) >> 30) + index;
    if (idx >= 1) {
        idx = idx - 1;
    }
    return self + idx * 0xa0 + 0xc;
}
