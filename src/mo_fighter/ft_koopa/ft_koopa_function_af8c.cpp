#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void fn_102_AF14(void*, short);

extern "C" void* fn_102_AF8C(void* object, short deleting) {
    if (object != 0) {
        fn_102_AF14(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
