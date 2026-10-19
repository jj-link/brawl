#pragma force_active on
extern "C" void* fn_27_5AE44(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_94_15540(void* p, short flag) {
    if (p != 0) {
        fn_27_5AE44(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
