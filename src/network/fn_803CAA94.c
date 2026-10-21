#pragma force_active on
extern int fn_803CAE6C(void* a, void* b, unsigned int c,
                       unsigned int d, unsigned int* e, void* f);

int fn_803CAA94(void* a, void* b, unsigned int c, void* d,
                unsigned int* e) {
    *e = 0;
    if (a == 0 || b == 0 || d == 0 || e == 0) {
        return -20;
    }
    return fn_803CAE6C(d, b, c, 0x200, e, a);
}
