#pragma force_active on
extern "C" char* fn_68_64FC(char* self, int index) {
    int s = *(int*)(self + 8) >> 30;
    int i = s + index;
    if (i >= 1) {
        i -= 1;
    }
    return self + i * 0x68 + 0xc;
}
