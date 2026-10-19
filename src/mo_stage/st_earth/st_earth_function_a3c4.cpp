#pragma force_active on
extern "C" void* fn_66_A3C4(char* self, int index) {
    int adj = (*(int*)(self + 8) >> 30) + index;
    if (adj >= 1) {
        adj--;
    }
    return self + adj * 0x38 + 0xc;
}
