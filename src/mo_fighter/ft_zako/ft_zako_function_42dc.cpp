#pragma force_active on
extern "C" void fn_27_69684(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_126_42DC(void* p, short flag) {
    if (p != 0) {
        fn_27_69684(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
