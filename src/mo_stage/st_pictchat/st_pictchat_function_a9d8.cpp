#pragma force_active on
extern "C" void* fn_73_A9D8(void* self, int index) {
    char* base = (char*)self;
    int i = (*(int*)(base + 8) >> 28) + index;
    if (i < 4) {
    } else {
        i -= 4;
    }
    return base + i * 0x90 + 0xc;
}
