#pragma force_active on
extern "C" {
void fn_70_20FC(void* p, int flags);
void __dl__FPv(void* p);

void* fn_70_262C(void* p, int n) {
    if (p) {
        fn_70_20FC(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
