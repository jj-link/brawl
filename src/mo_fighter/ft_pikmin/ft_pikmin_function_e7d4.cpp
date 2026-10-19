#pragma force_active on
extern "C" void* fn_113_E63C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_113_E7D4(void* object, short deleting) {
    if (object != 0) {
        fn_113_E63C(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
