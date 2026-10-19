#pragma force_active on
extern "C" {
void __dl__FPv(void*);

void* fn_27_1541A8(void* p, int n) {
    if (p != 0 && n > 0) {
        __dl__FPv(p);
    }
    return p;
}
}
