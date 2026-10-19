#pragma force_active on
extern "C" {
void fn_95_DDF8(void* p, short n);
void __dl__FPv(void* p);
void* fn_95_DE70(void* p, short flags);
}

void* fn_95_DE70(void* p, short flags) {
    if (p != 0) {
        fn_95_DDF8(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
