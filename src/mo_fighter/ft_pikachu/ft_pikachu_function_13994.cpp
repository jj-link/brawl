#pragma force_active on
extern "C" void* fn_98_47F8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_98_13994(void* accesser, int deleting) {
    if (accesser) {
        fn_98_47F8(accesser, 0);
        if (static_cast<short>(deleting) > 0) {
            __dl__FPv(accesser);
        }
    }
    return accesser;
}
