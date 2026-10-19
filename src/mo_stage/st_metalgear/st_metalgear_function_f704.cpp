#pragma force_active on
extern "C" char* fn_71_F704(char* self, int index) {
    int i = (*(int*)(self + 8) >> 30) + index;
    if (i >= 1) {
        i -= 1;
    }
    return self + i * 0x90 + 0xC;
}
