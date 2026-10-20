#pragma force_active on
extern "C" void* fn_27_D9A70(char* self, int idx) {
    int s = *(int*)(self + 8) >> 28;
    int i = s + idx;
    if (i >= 7) {
        i -= 7;
    }
    return self + 0xc + i * 0x24;
}
