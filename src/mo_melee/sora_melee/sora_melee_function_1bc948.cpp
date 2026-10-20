#pragma force_active on
extern "C" void* fn_27_1BC948(char* self, int idx) {
    int i = (*(int*)(self + 0x18) >> 27) + idx;
    if (i >= 10) {
        i -= 10;
    }
    return self + i * 12 + 0x1c;
}
