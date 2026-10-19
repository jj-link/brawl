#pragma force_active on
extern "C" void* fn_63_AF4C(char* self, int index) {
    int idx = (*(int*)(self + 8) >> 28) + index;
    if (idx >= 4) {
        idx -= 4;
    }
    return self + idx * 0x68 + 0xc;
}
