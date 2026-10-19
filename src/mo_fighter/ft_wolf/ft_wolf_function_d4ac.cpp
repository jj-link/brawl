#pragma force_active on
extern "C" void* fn_125_4CD8(void* ptr, short count);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_125_D4AC(void* object, short deleting) {
    if (object != 0) {
        fn_125_4CD8(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
