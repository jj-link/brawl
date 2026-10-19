#pragma force_active on
extern "C" void* fn_74_6BF0(void* self, int index) {
    int* p = (int*)self;
    int i = (p[2] >> 28) + index;
    if (i >= 6) {
        i -= 6;
    }
    return (char*)self + 0xC + i * 8;
}
