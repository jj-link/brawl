#pragma force_active on
extern "C" {
char* fn_76_3F98(char* self, int index) {
    int sh = *(int*)(self + 8) >> 27;
    int i = sh + index;
    if (i >= 9) {
        i -= 9;
    }
    return self + i * 0x68 + 0xc;
}
}
