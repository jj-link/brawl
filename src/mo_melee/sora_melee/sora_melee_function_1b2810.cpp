#pragma force_active on
extern "C" {
int fn_27_1B2810(void* p) {
    unsigned int x = *(unsigned int*)((char*)p + 8);
    return ((int)((x << 8) & 0xF8000000u)) >> 28;
}
}
