#pragma force_active on
extern "C" void* fn_115_6308(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_62AC(void* object, short deleting) {
    if (object != 0) {
        fn_115_6308(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
