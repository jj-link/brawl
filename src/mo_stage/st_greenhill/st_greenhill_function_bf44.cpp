#pragma force_active on
extern "C" char* fn_72_BF44(char* self, int index) {
    int idx = (*(int*)(self + 8) >> 29) + index;
    if (idx >= 3) {
        idx -= 3;
    }
    return self + idx * 0x68 + 0xc;
}
