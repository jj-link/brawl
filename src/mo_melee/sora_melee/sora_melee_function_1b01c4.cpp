#pragma force_active on
extern "C" void* fn_27_1B01C4(void* p, int idx) {
    int v = *(int*)((char*)p + 8);
    int n = (v >> 28) + idx;
    if (n >= 7) {
        n -= 7;
    }
    return (char*)p + (n << 4) + 0xC;
}
