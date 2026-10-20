#pragma force_active on
extern "C" {
void fn_27_2D90C0(void* p, int n);

void* fn_27_328A48(void* p, int n) {
    if (p) {
        fn_27_2D90C0(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
