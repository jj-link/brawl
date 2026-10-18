#pragma force_active on
extern "C" void* fn_115_15580(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_155E0(void* object, short deleting) {
    if (object != 0) {
        fn_115_15580(object, 0);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
