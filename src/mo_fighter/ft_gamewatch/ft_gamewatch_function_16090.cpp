#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_107_4898(void*, short);

extern "C" void* fn_107_16090(void* a, short b) {
    if (a != 0) {
        void* r = fn_107_4898(a, 0);
        (void)r;
        if (b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
