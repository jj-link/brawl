#pragma force_active on
extern "C" void* fn_27_1AF6D4(void* self, int idx) {
    char* p = (char*)self;
    int i = (*(int*)(p + 8) >> 22) + idx;
    if (i >= 0x1c0) {
        i -= 0x1c0;
    }
    return p + 0xc + i * 4;
}
