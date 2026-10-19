#pragma force_active on
extern "C" void* fn_54_E514(void* self, int index) {
    int i = (*(int*)((char*)self + 8) >> 28) + index;
    if (i >= 5) {
        i -= 5;
    }
    return (char*)self + i * 0x90 + 0xc;
}
