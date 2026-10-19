#pragma force_active on
extern "C" void* fn_27_B64B8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_102_2DC8(void* object, short deleting) {
    if (object != 0) {
        fn_27_B64B8(object, -1);
        if (deleting > 0)
            __dl__FPv(object);
    }
    return object;
}
