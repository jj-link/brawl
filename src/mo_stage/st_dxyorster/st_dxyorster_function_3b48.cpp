#pragma force_active on
void operator delete(void* p);

extern "C" {
void* fn_76_3B48(void* p, int n) {
    if (p != 0) {
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
