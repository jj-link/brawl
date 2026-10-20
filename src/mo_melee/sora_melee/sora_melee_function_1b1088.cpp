#pragma force_active on
extern "C" int* fn_27_1B1088(char* self, int idx) {
    int i = (*(int*)(self + 8) >> 27) + idx;
    if (i >= 10) {
        i -= 10;
    }
    return (int*)(self + 12 + i * 4);
}
