#pragma force_active on
extern "C" void fn_120_BC4C(void* object, short deleting);
extern "C" void fn_120_BB18(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_120_BCAC(void* object, short deleting) {
    if (object != 0) {
        fn_120_BC4C(static_cast<char*>(object) + 0x204, -1);
        if (object != 0) {
            fn_120_BB18(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
