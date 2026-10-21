#pragma force_active on
extern "C" int fn_801A66D8(void* a, void* b) {
    unsigned short vb = *(unsigned short*)((char*)b + 4);
    unsigned short va = *(unsigned short*)((char*)a + 4);
    if (va < vb) return 1;
    if (va > vb) return 0;
    return *(float*)a > *(float*)b;
}
