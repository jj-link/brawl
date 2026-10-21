#pragma force_active on

extern "C" void fn_801078B8(char* self, int arg) {
    char* p = *(char**)(self + 0x6C);
    if (p) {
        *(unsigned char*)(p + arg + 0x35) = 1;
        *(int*)(p + 0x3C) = arg;
    }
}
