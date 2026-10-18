#pragma force_active on
extern "C" void fn_123_39AC(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_123_12F7C(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            short zero = 0;
            fn_123_39AC(object, zero);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
