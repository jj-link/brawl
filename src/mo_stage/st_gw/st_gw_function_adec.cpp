#pragma force_active on
extern "C" void* fn_63_ADEC(void* self, int index) {
    int v = *(int*)((char*)self + 0x8);
    int n = (v >> 30) + index;
    n = (n >= 1) ? n - 1 : n;
    return (char*)self + n * 0xA0 + 0xC;
}
