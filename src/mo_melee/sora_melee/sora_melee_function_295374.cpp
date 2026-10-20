#pragma force_active on
extern "C" void* fn_27_295374(char* p, int idx) {
    int off = *(int*)(p + 0x18) >> 26;
    int sum = off + idx;
    if (sum >= 20) {
        sum -= 20;
    }
    return p + sum * 12 + 0x1c;
}
