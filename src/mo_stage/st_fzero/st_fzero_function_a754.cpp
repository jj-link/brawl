#pragma force_active on
extern "C" char* fn_61_A754(char* self, int index) {
    int s = *(int*)(self + 8) >> 30;
    int n = s + index;
    if (n >= 1) {
        n--;
    }
    return self + n * 0x90 + 0xc;
}
