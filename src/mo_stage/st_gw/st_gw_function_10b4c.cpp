#pragma force_active on
extern "C" void* fn_63_10B4C(void* self, int index) {
    char* base = (char*)self;
    int i = (*(int*)(base + 0x8) >> 30) + index;
    if (i >= 1) {
        i = i - 1;
    }
    return base + i * 0x90 + 0xc;
}
