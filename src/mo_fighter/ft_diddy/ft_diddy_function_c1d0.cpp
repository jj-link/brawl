#pragma force_active on
extern "C" void* fn_115_C038(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_C1D0(void* object, short deleting) {
    if (object) {
        fn_115_C038(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
