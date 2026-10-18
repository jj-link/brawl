#pragma force_active on
extern "C" void fn_115_1B08(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_1C80(void* p, short flag) {
    if (p != 0) {
        fn_115_1B08(p, 0);
        if (flag > 0)
            __dl__FPv(p);
    }
    return p;
}
