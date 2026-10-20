#pragma force_active on
extern "C" {
void* fn_27_FEE24(void* p, int n) {
    int idx = (*(int*)((char*)p + 8) >> 26) + n;
    if (idx >= 0x17) {
        idx -= 0x17;
    }
    return (char*)p + idx * 12 + 12;
}
}
