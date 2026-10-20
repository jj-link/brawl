#pragma force_active on
extern "C" {
void* fn_27_1AF83C(char* self, int idx) {
    int n = (*(int*)(self + 8) >> 22) + idx;
    if (n >= 0x124) {
        n -= 0x124;
    }
    return self + n * 4 + 0xc;
}
}
