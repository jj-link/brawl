#pragma force_active on
extern "C" {
void fn_112_5958(void* p, short flags);
void __dl__FPv(void* p);

void* fn_112_112F0(void* p, short flags) {
    if (p != 0) {
        fn_112_5958(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
