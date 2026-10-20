#pragma force_active on
extern "C" void* fn_27_385C40(void* a, int b) {
    int idx = (*(int*)((char*)a + 8) >> 22) + b;
    if (idx >= 0x12b) {
        idx -= 0x12b;
    }
    return (char*)a + idx * 4 + 0xc;
}
