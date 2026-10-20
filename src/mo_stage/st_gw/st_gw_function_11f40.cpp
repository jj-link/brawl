#pragma force_active on
extern "C" {
int fn_63_11F40(void* p) {
    unsigned int x = *(unsigned int*)((char*)p + 8);
    int r = (int)(((x << 2) | (x >> 30)) & 0xE0000000u);
    return r >> 30;
}
}
