#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_41_2A480(void* p, short n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
