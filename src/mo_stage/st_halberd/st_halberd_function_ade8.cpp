#pragma force_active on
extern "C" void* fn_57_ADE8(void* self, int index) {
    char* base = (char*)self;
    int idx = (*(int*)(base + 8) >> 29) + index;
    if (idx >= 2) {
        idx -= 2;
    }
    return base + idx * 0x90 + 0xc;
}
