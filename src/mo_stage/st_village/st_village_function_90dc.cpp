#pragma force_active on
extern "C" void* fn_70_90DC(char* base, int index) {
    int i = (*(int*)(base + 8) >> 30) + index;
    if (i >= 1) {
        i = i - 1;
    }
    return base + i * 0x38 + 0xc;
}
