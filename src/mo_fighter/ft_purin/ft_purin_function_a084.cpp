#pragma force_active on
extern "C" void fn_124_8414(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_124_A084(void* p, short flag) {
    if (p != 0) {
        fn_124_8414(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
