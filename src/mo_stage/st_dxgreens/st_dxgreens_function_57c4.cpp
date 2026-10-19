#pragma force_active on
extern "C" void* fn_79_57C4(unsigned char* self, int index) {
    int offset = *(int*)(self + 8) >> 26;
    int sum = offset + index;
    if (sum >= 30) {
        sum -= 30;
    }
    return self + sum * 160 + 12;
}
