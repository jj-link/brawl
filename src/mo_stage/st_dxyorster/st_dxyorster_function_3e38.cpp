#pragma force_active on
extern "C" char* fn_76_3E38(char* p, int idx) {
    int n = (*(int*)(p + 8) >> 27) + idx;
    if (n >= 9) {
        n -= 9;
    }
    return p + n * 0x38 + 0xC;
}
