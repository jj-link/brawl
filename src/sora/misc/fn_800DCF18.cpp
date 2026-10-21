#pragma force_active on

extern "C" void fn_800DCF18(char* self, int idx) {
    char* p = *(char**)(self + 0x94);
    if (p == 0) {
        return;
    }
    *(unsigned char*)(p + idx + 0x35) = 1;
    *(int*)(p + 0x3C) = idx;
}
