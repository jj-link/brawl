#pragma force_active on
extern "C" void* fn_73_AA70(void* self, int index) {
    int v = *(int*)((char*)self + 8);
    int i = (v >> 28) + index;
    if (i >= 5) {
        i -= 5;
    }
    return (char*)self + i * 0x90 + 0xC;
}
