#pragma force_active on
extern "C" void fn_125_3E50(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_3DF0(void* object, short deleting) {
    if (object != 0) {
        fn_125_3E50((char*)object + 12, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
