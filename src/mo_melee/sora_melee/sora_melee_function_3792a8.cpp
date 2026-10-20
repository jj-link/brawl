#pragma force_active on
extern "C" void fn_27_C21DC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_27_3792A8(void* p, int flag) {
    if (p) {
        fn_27_C21DC(p, -1);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
