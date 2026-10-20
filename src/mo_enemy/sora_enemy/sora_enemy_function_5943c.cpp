#pragma force_active on
extern "C" void fn_41_59370(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_5943C(void* p, short flag) {
    if (p) {
        if (p) {
            fn_41_59370((char*)p + 4, -1);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
