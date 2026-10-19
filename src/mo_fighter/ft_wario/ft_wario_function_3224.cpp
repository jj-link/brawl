#pragma force_active on
extern "C" {
void* fn_27_19874C(void*, short);
void __dl__FPv(void*);

void* fn_110_3224(void* p, short flags) {
    if (p != 0) {
        fn_27_19874C(p, -1);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
