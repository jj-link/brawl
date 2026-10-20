#pragma force_active on
extern "C" void* fn_27_1AF8B4(char* self, int idx) {
    int i = (*(int*)(self + 8) >> 22) + idx;
    if (i >= 0x121) {
        i -= 0x121;
    }
    return self + 0xc + i * 4;
}
