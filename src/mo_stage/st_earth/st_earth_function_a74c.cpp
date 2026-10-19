#pragma force_active on
extern "C" void* fn_66_A74C(void* self, int index) {
    int v = *(int*)((char*)self + 8);
    int i = (v >> 28) + index;
    if (i >= 6) {
        i -= 6;
    }
    return (char*)self + 0xc + i * 8;
}
