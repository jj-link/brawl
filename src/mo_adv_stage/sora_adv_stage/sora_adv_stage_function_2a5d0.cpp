#pragma force_active on
extern "C" void fn_27_272DD8(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_40_2A5D0(void* p, int flags) {
    if (p != 0) {
        fn_27_272DD8(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
