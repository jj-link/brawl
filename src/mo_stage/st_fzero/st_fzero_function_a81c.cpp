#pragma force_active on
extern "C" void* fn_61_A81C(unsigned char* self, int index) {
    int n = (*(int*)(self + 8) >> 28) + index;
    if (n >= 7) {
        n -= 7;
    }
    return self + 0xc + n * 8;
}
