#pragma force_active on
extern "C" void fn_27_7700(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_1F6C(void* p, short flag) {
    if (p != 0) {
        fn_27_7700(p, static_cast<short>(0));
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
