#pragma force_active on
extern "C" char* fn_71_9FE0(char* self, int index) {
    int sh = *(int*)(self + 8) >> 30;
    int i = sh + index;
    if (i >= 1) {
        i--;
    }
    return self + i * 0x38 + 0xC;
}
