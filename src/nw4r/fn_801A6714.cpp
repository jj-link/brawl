#pragma force_active on
extern "C" int fn_801A6714(void* a, void* b) {
    unsigned short vb = *(unsigned short*)((char*)b + 4);
    unsigned short va = *(unsigned short*)((char*)a + 4);
    if (va < vb) return 1;
    if (va > vb) return 0;
    if (*(float*)a < *(float*)b) return 1;
    if (*(float*)a == *(float*)b) {
        unsigned short sa = *(unsigned short*)((char*)a + 8);
        unsigned short sb = *(unsigned short*)((char*)b + 8);
        if (sa < sb) return 1;
    }
    return 0;
}
