#pragma force_active on
extern "C" {
void fn_800AD87C(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_8015B17C(void* p, int n) {
    if (p) {
        if (*(void**)p) {
            fn_800AD87C(*(void**)p, 1);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
