#pragma force_active on
extern "C" void* fn_51_65E8(void* self, int index) {
    char* base = (char*)self;
    int n = (*(int*)(base + 8) >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return base + n * 0x68 + 0xC;
}
