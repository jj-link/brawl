#pragma force_active on
extern "C" {
void* fn_27_B137C(void* self, int idx) {
    int x = *(int*)((char*)self + 8);
    int n = (x >> 27) + idx;
    if (n >= 8) {
        n -= 8;
    }
    return (char*)self + n * 8 + 12;
}
}
