#pragma force_active on
extern "C" void* fn_54_6920(unsigned char* self, int index) {
    int bias = *(int*)(self + 8) >> 28;
    int sum = bias + index;
    if (sum >= 7) {
        sum -= 7;
    }
    return self + (sum << 3) + 12;
}
