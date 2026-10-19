#pragma force_active on
extern "C" void* fn_102_1B108(void* object, short deleting);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_1B0AC(void* object, short deleting) {
    if (object != 0) {
        fn_102_1B108(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
