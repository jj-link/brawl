#pragma force_active on
extern "C" void* fn_62_A6FC(char* self, int index) {
    int off = *(int*)(self + 8) >> 28;
    int i = off + index;
    if (i >= 6) {
        i = i - 6;
    }
    return self + i * 8 + 12;
}
