#pragma force_active on
extern "C" char* fn_67_4FB0(char* self, int index) {
    int bias = *(int*)(self + 8) >> 30;
    int n = bias + index;
    if (n >= 1) {
        n--;
    }
    return self + n * 0xA0 + 0xC;
}
