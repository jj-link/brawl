#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void* fn_73_9774(void* p, int n);
}

extern "C" void* fn_73_9774(void* p, int n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
