#pragma force_active on
extern "C" void* fn_66_A4F4(char* self, int index) {
    int i = (*(int*)(self + 8) >> 30) + index;
    if (i >= 1) {
        i -= 1;
    }
    return self + i * 0x90 + 0xc;
}
