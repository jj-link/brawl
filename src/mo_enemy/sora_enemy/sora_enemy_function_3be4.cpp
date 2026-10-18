#pragma force_active on
extern "C" int fn_41_3BE4(char* p) {
    char* q = *(char**)(p + 0x91c);
    if (q == 0) {
        return 0xFFFF;
    }
    return *(int*)(q + 0x14);
}
