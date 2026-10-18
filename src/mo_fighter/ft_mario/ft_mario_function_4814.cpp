#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_91_4814(void* object, short deleting) {
    if (object != 0) {
        if (object != 0) {
            fn_27_1A15B8(object, static_cast<short>(-1));
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
