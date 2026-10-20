#pragma force_active on
extern "C" {
void fn_102_1AA4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_102_1B64(void* p, short flags) {
    if (p != 0) {
        fn_102_1AA4(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
