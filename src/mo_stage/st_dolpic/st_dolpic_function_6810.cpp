#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_46_6810(void* p, int n);
}

extern "C" void* fn_46_6810(void* p, int n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
