#pragma force_active on
extern "C" {
void* fn_27_14F384(int* p, int idx) {
    int r = (p[2] >> 25) + idx;
    if (r >= 0x20) {
        r -= 0x20;
    }
    return (char*)p + r * 4 + 0xC;
}
}
