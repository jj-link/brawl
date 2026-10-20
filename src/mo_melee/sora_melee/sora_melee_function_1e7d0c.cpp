#pragma force_active on
extern "C" void* fn_27_1E7D0C(void* self, int idx) {
    int* words = (int*)self;
    int v = (words[2] >> 30) + idx;
    if (v >= 1) {
        v -= 1;
    }
    return (char*)self + v * 12 + 12;
}
