#pragma force_active on
extern "C" void* fn_115_15D7C(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_15DDC(void* object, short deleting) {
    if (object != 0) {
        fn_115_15D7C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
