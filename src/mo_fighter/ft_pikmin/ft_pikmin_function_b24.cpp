#pragma force_active on
extern "C" void fn_27_1362C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_B24(void* p, short flag) {
    if (p != 0) {
        fn_27_1362C(p, 0);
        if (static_cast<short>(flag) > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
