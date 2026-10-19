#pragma force_active on
extern "C" void* fn_77_3CD8(char* self, int index) {
    int count = *(int*)(self + 8);
    int n = (count >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return self + n * 0x90 + 0xc;
}
