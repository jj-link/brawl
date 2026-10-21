#pragma force_active on
extern "C" {
void __dt__Q22ms10CharWriterFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_80070B38(void* p, int n) {
    if (p) {
        __dt__Q22ms10CharWriterFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
