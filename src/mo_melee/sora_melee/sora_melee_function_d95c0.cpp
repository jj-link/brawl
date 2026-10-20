#pragma force_active on
extern "C" {
void* fn_27_D95C0(char* p, int idx);
}

void* fn_27_D95C0(char* p, int idx) {
    int v = *(int*)(p + 8) >> 26;
    int n = v + idx;
    if (n >= 17) {
        n -= 17;
    }
    return p + n * 0x30 + 0xc;
}
