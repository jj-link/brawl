#pragma force_active on
extern "C" void* fn_27_1ACB7C(void* p, int idx) {
    int v = *(int*)((char*)p + 0x18);
    int t = (v >> 28) + idx;
    if (t >= 6) {
        t -= 6;
    }
    return (char*)p + (t << 4) + 0x1c;
}
