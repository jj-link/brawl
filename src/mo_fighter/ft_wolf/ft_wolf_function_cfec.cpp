#pragma force_active on
extern "C" void fn_125_CE54(void* object, short deleting);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_125_CFEC(void* object, short deleting) {
    if (object != 0) {
        fn_125_CE54(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
