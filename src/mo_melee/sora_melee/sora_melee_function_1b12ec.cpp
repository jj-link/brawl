#pragma force_active on
extern "C" {
void* fn_27_1B12EC(char* p, int i) {
    int a = *(int*)(p + 8) >> 28;
    int b = a + i;
    if (b >= 6) {
        b -= 6;
    }
    return p + 0xc + (b << 4);
}
}
