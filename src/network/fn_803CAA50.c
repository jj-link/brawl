#pragma force_active on
extern int fn_803CACCC(void* a, void* b, int c, int d, int* e, void* f);

int fn_803CAA50(void* a, void* b, int c, void* d, int* e) {
    *e = 0;
    if (a == 0 || b == 0 || d == 0 || e == 0) {
        return -20;
    }
    return fn_803CACCC(d, b, c, 0x200, e, a);
}
