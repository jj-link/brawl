#pragma force_active on
extern "C" char* fn_57_AD50(char* self, int index) {
    int adj = (*(int*)(self + 8) >> 30) + index;
    if (adj >= 1) {
        adj = adj - 1;
    }
    return self + adj * 0x78 + 0xC;
}
