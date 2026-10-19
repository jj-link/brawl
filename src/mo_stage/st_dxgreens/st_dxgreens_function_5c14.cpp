#pragma force_active on
extern "C" char* fn_79_5C14(char* self, int n) {
    int v = *(int*)(self + 8);
    int idx = (v >> 28) + n;
    if (idx < 7) {
    } else {
        idx -= 7;
    }
    return self + idx * 8 + 0xc;
}
