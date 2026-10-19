#pragma force_active on
extern "C" void fn_51_3C30(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_51_E34C(void* p, int flag) {
    if (p != 0) {
        fn_51_3C30(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
