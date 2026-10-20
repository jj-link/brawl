#pragma force_active on
extern "C" char* fn_27_D97C8(void* self, int p2) {
    int s = *(int*)((char*)self + 8) >> 29;
    int n = s + p2;
    if (n >= 3) {
        n -= 3;
    }
    return (char*)self + n * 0x90 + 0xC;
}
