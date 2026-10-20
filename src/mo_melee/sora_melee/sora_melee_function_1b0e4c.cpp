#pragma force_active on
extern "C" void* fn_27_1B0E4C(void* self, int idx) {
    char* p = (char*)self;
    int v = *(int*)(p + 8);
    int i = (v >> 27) + idx;
    if (i >= 15) {
        i -= 15;
    }
    return p + i * 0x60 + 0xc;
}
