#pragma force_active on
extern "C" char* fn_73_AC68(char* self, int index) {
    int n = (*(int*)(self + 8) >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return self + 0xC + n * 0x78;
}
