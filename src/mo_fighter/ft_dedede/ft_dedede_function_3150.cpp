#pragma force_active on
extern "C" void* fn_27_A0C34(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_117_3150(void* object, short deleting) {
    if (object != 0) {
        fn_27_A0C34(object, static_cast<short>(-1));
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
