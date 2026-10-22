#pragma force_active on
extern "C" {
void** fn_801B5DC0(void**, void*);
}

extern "C" void* fn_801AC5F4(char* arg0, int arg1) {
    void* spC;
    void* sp8;

    if (arg1 >= 0 && arg1 < 0x20) {
        return *fn_801B5DC0(&spC, arg0 + arg1 * 0x30 + 0x2278);
    }
    return *fn_801B5DC0(&sp8, 0);
}
