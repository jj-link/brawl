#pragma force_active on
extern "C" {
void fn_52_363C(void* self, int flags);
void __dl__FPv(void* p);

void* fn_52_102EC(void* p, int flags) {
    if (p != 0) {
        fn_52_363C(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
