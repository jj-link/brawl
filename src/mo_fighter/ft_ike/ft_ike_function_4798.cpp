#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" void* fn_27_5B39C(void*, short);

extern "C" void* fn_119_4798(void* object, short deleting) {
    if (object != 0) {
        fn_27_5B39C(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
