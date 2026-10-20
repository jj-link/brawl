#pragma force_active on
extern "C" {
void* fn_27_1B08F0(char* p, int idx) {
    int v = *(int*)(p + 8);
    int t = (v >> 27) + idx;
    if (t >= 14) {
        t -= 14;
    }
    return p + t * 0x60 + 0xc;
}
}
