#pragma force_active on
extern "C" void* fn_27_1C3FF8(void* self, int idx) {
    int v = *(int*)((char*)self + 0x18);
    int n = (v >> 29) + idx;
    if (n >= 2) {
        n -= 2;
    }
    return (char*)self + n * 12 + 0x1c;
}
