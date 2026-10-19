#pragma force_active on
extern "C" void* fn_52_75E0(void* self, int index) {
    int adj = *(int*)((char*)self + 8) >> 30;
    int idx = adj + index;
    if (idx >= 1) {
        idx = idx - 1;
    }
    return (char*)self + idx * 0x90 + 0xc;
}
