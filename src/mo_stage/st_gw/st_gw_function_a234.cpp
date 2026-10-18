#pragma force_active on
void operator delete(void* p);

extern "C" {
void* fn_63_A234(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
