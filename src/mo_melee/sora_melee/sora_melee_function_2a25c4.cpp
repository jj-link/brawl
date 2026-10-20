#pragma force_active on
extern "C" {
void fn_27_2A25C4(char* self, int a, int b) {
    if (a < 0) {
        a = -1;
    }
    if (b < 0) {
        b = -1;
    }
    *(int*)(self + 0x148c) = a;
    *(int*)(self + 0x1490) = b;
}
}
