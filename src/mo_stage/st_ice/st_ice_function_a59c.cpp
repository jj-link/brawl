#pragma force_active on
extern "C" void* fn_62_A59C(char* self, int index) {
    int n = (*(int*)(self + 8) >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return self + n * 0x38 + 0xc;
}
