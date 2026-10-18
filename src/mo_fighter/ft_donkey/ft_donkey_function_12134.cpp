#pragma force_active on
extern "C" void* fn_27_1A2D10(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_92_12134(void* object, short deleting) {
    if (object != 0) {
        fn_27_1A2D10(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
