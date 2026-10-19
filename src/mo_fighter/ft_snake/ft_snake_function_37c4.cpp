#pragma force_active on
extern "C" void* fn_122_3820(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_122_37C4(void* object, short deleting) {
    if (object != 0) {
        fn_122_3820(object, 0);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
