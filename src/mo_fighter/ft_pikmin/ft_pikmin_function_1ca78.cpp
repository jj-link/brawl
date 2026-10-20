#pragma force_active on
extern "C" void* fn_113_1CA00(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_113_1CA78(void* object, short deleting) {
    if (object != 0) {
        short zero = 0;
        fn_113_1CA00(object, zero);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
