#pragma force_active on
extern "C" void* fn_71_A0A8(void* self, int index) {
    char* base = (char*)self;
    int n = (*(int*)(base + 8) >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return base + n * 0x78 + 0xc;
}
