#pragma force_active on
extern "C" void* fn_41_15FD4(char* p, int idx);

extern "C" int fn_41_1602C(char* p, void* q) {
    for (int i = 0; i < 8; i++) {
        if (q == fn_41_15FD4(p, i)) {
            return i;
        }
    }
    return -1;
}
