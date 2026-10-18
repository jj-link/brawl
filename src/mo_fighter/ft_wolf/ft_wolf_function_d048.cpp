#pragma force_active on
extern "C" void fn_125_CFEC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_D048(void* object, short deleting) {
    if (object != 0) {
        fn_125_CFEC(static_cast<char*>(object) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
