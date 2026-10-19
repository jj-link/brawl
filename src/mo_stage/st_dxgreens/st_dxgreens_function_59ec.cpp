#pragma force_active on
extern "C" void* fn_79_59EC(char* self, int index) {
    int idx = (*(int*)(self + 8) >> 26) + index;
    if (idx >= 30) {
        idx -= 30;
    }
    return self + idx * 0x68 + 0xc;
}
