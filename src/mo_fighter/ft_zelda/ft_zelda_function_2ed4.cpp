#pragma force_active on
extern "C" void fn_27_ACC5C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_104_2ED4(void* p, short flag) {
    if (p != 0) {
        fn_27_ACC5C(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
