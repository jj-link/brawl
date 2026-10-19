#pragma force_active on
extern "C" char* fn_67_5078(char* self, int index) {
    int adj = *(int*)(self + 8) >> 30;
    int n = adj + index;
    if (n >= 1) {
        n--;
    }
    return self + n * 0x38 + 0xc;
}
