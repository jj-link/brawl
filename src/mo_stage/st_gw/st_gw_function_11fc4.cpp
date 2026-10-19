#pragma force_active on
extern "C" void* fn_63_11FC4(char* self, int index) {
    int adj = (*(int*)(self + 8) >> 30) + index;
    if (adj >= 1) {
        adj = adj - 1;
    }
    return self + 0xC + adj * 0x68;
}
