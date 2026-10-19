#pragma force_active on
extern "C" void* fn_51_6550(char* self, int index) {
    int i = (*(int*)(self + 8) >> 30) + index;
    if (i >= 1) {
        i -= 1;
    }
    return self + 0xC + i * 0x38;
}
