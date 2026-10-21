#pragma force_active on
extern "C" {
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_800DABC8(void* p, int n) {
    if (p) {
        __dt__6gfTaskFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
