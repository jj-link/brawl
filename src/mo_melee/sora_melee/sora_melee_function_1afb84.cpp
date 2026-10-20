#pragma force_active on
extern "C" void* fn_27_1AFB84(void* p, int idx) {
    int v = *(int*)((char*)p + 0x8);
    int i = (v >> 28) + idx;
    if (i >= 6) {
        i -= 6;
    }
    return (char*)p + 0xc + i * 4;
}
