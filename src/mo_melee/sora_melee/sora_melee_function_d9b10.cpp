#pragma force_active on
extern "C" void* fn_27_D9B10(void* p, int n) {
    char* base = (char*)p;
    int v = *(int*)(base + 8);
    int idx = (v >> 27) + n;
    if (idx >= 12) {
        idx -= 12;
    }
    return base + idx * 36 + 12;
}
