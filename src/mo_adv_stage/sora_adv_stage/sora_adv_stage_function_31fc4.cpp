#pragma force_active on
extern "C" void fn_40_27868(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_40_31FC4(void* p, int flag) {
    if (p) {
        fn_40_27868(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
