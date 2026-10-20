#pragma force_active on
extern "C" int fn_27_3241DC(char* p, int unused, int x, int idx) {
    int off = (x - *(int*)(p + 0x14)) << 2;
    int* base = *(int**)(p + off + 0x24);
    return base[idx];
}
